#ifndef TIMEKEEPER_CUMULATIVE_RECORDS_H_INCLUDED
#define TIMEKEEPER_CUMULATIVE_RECORDS_H_INCLUDED
/*
 *  This file is part of the gobelijn software.
 *  Gobelijn is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or any later
 *  version. Gobelijn is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for details. You should have received
 *  a copy of the GNU General Public License along with the software. If not,
 *  see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2012, Jan Broeckhove.
 */
/**
 * @file
 * Utility class to record durations in a cumulative manner.
 */

#include "timekeeper/Utils.h"
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

namespace UA_CoMP {
namespace Timekeeper {

/**
 * Records durations associated with a name.
 * Template parameter is duration type (default std::chrono::seconds).
 */
template <typename T = std::chrono::seconds>
class CumulativeRecords
{
public:
        using Duration = T;

        /// Clear the entire set of records.
        void Clear() { m_map.clear(); }

        /// Return count for records with name.
        unsigned int GetCount(const std::string& name) const { return IsPresent(name) ? m_map.at(name).first : 0U; }

        /// Return cumulative time for records with name
        Duration GetCumulative(const std::string& name) const
        {
                return IsPresent(name) ? m_map.at(name).second : T::duration::zero();
        }

        /// Return cumulative time for records with name.
        Duration GetMean(const std::string& name) const
        {
                const auto count = GetCount(name);
                return (count > 0U) ? GetCumulative(name) / count : T::duration::zero();
        }

        /// Return list of names.
        std::list<std::string> GetNames() const
        {
                std::list<std::string> l;
                for (auto const& p : m_map) {
                        l.push_back(p.first);
                }
                return l;
        }

        /// Return records for all names in duration unit U.
        template <typename U = std::chrono::seconds>
        CumulativeRecords<U> GetRecords() const
        {
                CumulativeRecords<U> rec;
                for (auto const& p : m_map) {
                        rec.Record(p.first, GetCumulative(p.first));
                }
                return rec;
        }

        /// Return records for all names in durations Duration (so no casting).
        CumulativeRecords<Duration> GetRecords() const { return *this; }

        /// Return whether there are records associated with a given name.
        bool IsPresent(const std::string& name) const { return (m_map.find(name) != m_map.end()); }

        /// Merge an extra set of records (casting durations if required).
        template <typename U>
        void Merge(const CumulativeRecords<U>& extra)
        {
                Merge(extra.template GetRecords<Duration>());
        }

        /// Merge an extra set of records of same Duration (no casting).
        void Merge(const CumulativeRecords<Duration>& extra)
        {
                for (const auto& p : extra.m_map) {
                        const auto it = m_map.find(p.first);
                        if (it != m_map.end()) {
                                (it->second).first += (p.second).first;
                                (it->second).second += (p.second).second;
                        } else {
                                m_map[p.first] = p.second;
                        }
                }
        }

        /// Record the duration for the given name.
        template <typename R, typename P>
        void Record(const std::string& name, const std::chrono::duration<R, P>& duration)
        {
                const auto it = m_map.find(name);
                if (it != m_map.end()) {
                        (it->second).first++;
                        (it->second).second += std::chrono::duration_cast<T>(duration);
                } else {
                        m_map[name] = make_pair(1U, std::chrono::duration_cast<T>(duration));
                }
        }

        /// Record the duration for the given name.
        void Record(const std::string& name, const Duration& duration)
        {
                const auto it = m_map.find(name);
                if (it != m_map.end()) {
                        (it->second).first++;
                        (it->second).second += duration;
                } else {
                        m_map[name] = make_pair(1U, duration);
                }
        }

private:
        std::map<std::string, std::pair<unsigned int, Duration>> m_map;
};

/**
 * Pretty print of chrono recordings on output stream.
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& os, CumulativeRecords<T> const& dr)
{
        using namespace std;
        using namespace std::chrono;

        os << right << "duration records:  name   |   mean   |   stddev" << endl;

        auto name_list = dr.GetNames();
        name_list.sort();
        for (auto const& name : name_list) {
                auto const mean = dr.GetMean(name);
                auto const stddev = dr.GetStandardDeviation(name);

                os << right << setw(15) << name << "  |  " << setw(15) << Utils::ToColonString(mean) << setw(10)
                   << scientific << setprecision(4) << mean.count() << "  |  " << setw(15)
                   << Utils::ToColonString(stddev) << setw(10) << scientific << setprecision(4) << stddev.count()
                   << endl;
        }
        return os;
}

/**
 * Specializes for nicely formated output with milliseconds.
 */
template <>
inline std::ostream& operator<<<std::chrono::milliseconds>(std::ostream& os,
                                                           CumulativeRecords<std::chrono::milliseconds> const& dr)
{
        using namespace std;
        using namespace std::chrono;

        os << right << "timings:   " << endl
           << setw(14) << "name"
           << " | " << setw(21) << "(hh:mm:ss:ms) |     (ms) | " << setw(7) << "count"
           << " | " << setw(21) << "(hh:mm:ss:ms) |     (ms) | " << endl
           << string(80, '-') << endl;

        auto name_list = dr.GetNames();
        name_list.sort();
        for (auto const& name : name_list) {
                auto const count = dr.GetCount(name);
                auto const cumul_val = dr.GetCumulative(name);
                auto const cumul = duration_cast<milliseconds>(cumul_val);
                auto const avg_val = (count != 0) ? (cumul_val / count) : milliseconds::zero();
                auto const avg = duration_cast<milliseconds>(avg_val);

                os << right << setw(14) << name << " | " << setw(13) << Utils::ToColonString(cumul) << " | " << setw(8)
                   << scientific << setprecision(4) << cumul.count() << " | " << setw(7) << count << " | " << setw(13)
                   << Utils::ToColonString(avg) << " | " << setw(8) << scientific << setprecision(4) << avg.count()
                   << " | " << endl;
        }
        return os;
}

/**
 * Specializes for nicely formated output with seconds.
 */
template <>
inline std::ostream& operator<<<std::chrono::seconds>(std::ostream& os,
                                                      CumulativeRecords<std::chrono::seconds> const& dr)
{
        using namespace std;
        using namespace std::chrono;

        os << right << "timings:   " << endl
           << setw(14) << "name"
           << " | " << setw(20) << " (hh:mm:ss)  |    (s)  | " << setw(7) << "count"
           << " | " << setw(20) << " (hh:mm:ss)  |     (s) | " << endl
           << string(76, '-') << endl;

        auto name_list = dr.GetNames();
        name_list.sort();
        for (auto const& name : name_list) {
                auto const count = dr.GetCount(name);
                auto const cumul_val = dr.GetCumulative(name);
                auto const cumul = duration_cast<seconds>(cumul_val);
                auto const avg_val = (count != 0) ? (cumul_val / count) : seconds::zero();
                auto const avg = duration_cast<seconds>(avg_val);

                os << right << setw(14) << name << " | " << setw(12) << Utils::ToColonString(cumul) << " | " << setw(7)
                   << scientific << setprecision(4) << cumul.count() << " | " << setw(7) << count << " | " << setw(12)
                   << Utils::ToColonString(avg) << " | " << setw(7) << scientific << setprecision(4) << avg.count()
                   << " | " << endl;
        }
        return os;
}

} // namespace Clock
} // namespace UA_CoMP

#endif // end-of-include-guard
