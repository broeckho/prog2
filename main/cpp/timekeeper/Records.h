#ifndef TIMEKEEPER_RECORDS_H_INCLUDED
#define TIMEKEEPER_RECORDS_H_INCLUDED
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
 *  Copyright 2012, 2013, Jan Broeckhove.
 */
/**
 * @file
 * Utility class to record durations.
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
#include <vector>

namespace UA_CoMP {
namespace Timekeeper {

/**
 * Records durations associated with a name.
 * Template parameter is duration type (default std::chrono::seconds).
 */
template <typename T = std::chrono::seconds>
class Records
{
public:
        using Duration = T;

        /// Clear the entire set of records.
        void Clear() { m_map.clear(); }

        /// Return count for records with name.
        unsigned int GetCount(const std::string& name) const
        {
                return IsPresent(name) ? (m_map.find(name)->second).size() : 0;
        }

        /// Return cumulative time for records with name
        Duration GetCumulative(const std::string& name) const
        {
                Duration cumul = T::duration::zero();
                if (IsPresent(name)) {
                        std::vector<Duration> const& v = m_map.find(name)->second;
                        cumul = std::accumulate(v.begin(), v.end(), T::duration::zero());
                }
                return cumul;
        }

        /// Return cumulative time for records with name.
        Duration GetMean(const std::string& name) const
        {
                Duration cumul = T::duration::zero();
                unsigned int const count = GetCount(name);
                if (count > 0U) {
                        std::vector<Duration> const& v = m_map.find(name)->second;
                        cumul = std::accumulate(v.begin(), v.end(), T::duration::zero());
                        cumul /= count;
                }
                return cumul;
        }

        /// Return minimum time for records with name.
        Duration GetMinimum(const std::string& name) const
        {
                Duration minimum = T::duration::zero();
                if (GetCount(name) > 0U) {
                        std::vector<Duration> const& v = m_map.find(name)->second;
                        if (v.size() > 0) {
                                minimum = v[0];
                                for (auto const& el : v) {
                                        minimum = ((minimum <= el) ? minimum : el);
                                }
                        }
                }
                return minimum;
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

        /// Return records associated with given name.
        std::vector<Duration> GetRecord(const std::string& name) const
        {
                std::vector<Duration> v;
                if (IsPresent(name)) {
                        v = m_map.find(name)->second;
                }
                return v;
        }

        /// Return records for all names in durations U (casting if required).
        template <typename U = std::chrono::seconds>
        Records<U> GetRecords() const
        {
                Records<U> rec;
                for (auto const& p : m_map) {
                        for (auto const& v : p.second) {
                                rec.Record(p.first, std::chrono::duration_cast<U>(v));
                        }
                }
                return rec;
        }

        /// Return records for all names in durations Duration (so no casting).
        Records<Duration> GetRecords() const { return *this; }

        /// Return standard deviation for record with given name.
        Duration GetStandardDeviation(const std::string& name) const
        {
                Duration deviation = T::duration::zero();
                if (IsPresent(name)) {
                        std::vector<Duration> const& v = m_map.find(name)->second;
                        Duration const mean = GetMean(name);
                        typename Duration::rep cov = 0;
                        for (auto const& e : v) {
                                typename Duration::rep const x = (e - mean).count();
                                cov += x * x;
                        }
                        typename Duration::rep const x = std::sqrt(cov);
                        deviation = Duration(x);
                }
                return deviation;
        }

        /// Return whether there are records associated with a given name.
        bool IsPresent(const std::string& name) const { return (m_map.find(name) != m_map.end()); }

        /// Merge an extra set of records (casting durations if required).
        template <typename U>
        void Merge(const Records<U>& extra)
        {
                for (auto const& name : extra.GetNames()) {
                        for (auto const& elem : extra.GetRecord(name)) {
                                Record(name, std::chrono::duration_cast<T>(elem));
                        }
                }
        }

        /// Merge an extra set of records of same Duration (no casting).
        void Merge(const Records<Duration>& extra)
        {
                for (auto const& name : extra.GetNames()) {
                        if (IsPresent(name)) {
                                m_map[name].insert(m_map[name].end(), extra.m_map.at(name).begin(),
                                                   extra.m_map.at(name).end());
                        } else {
                                m_map[name] = extra.m_map.at(name);
                        }
                }
        }

        /// Record the duration for the given name.
        template <typename R, typename P>
        void Record(const std::string& name, const std::chrono::duration<R, P>& duration)
        {
                m_map[name].push_back(std::chrono::duration_cast<T>(duration));
        }

private:
        std::map<std::string, std::vector<Duration>> m_map;
};

/**
 * Pretty print of chrono recordings on output stream.
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& os, Records<T> const& dr)
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
                                                           Records<std::chrono::milliseconds> const& dr)
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
inline std::ostream& operator<<<std::chrono::seconds>(std::ostream& os, Records<std::chrono::seconds> const& dr)
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

} // namespace Timekeeper
} // namespace UA_CoMP

#endif // end-of-include-guard
