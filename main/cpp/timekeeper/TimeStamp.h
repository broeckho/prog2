#ifndef TIMEKEEPER_TIMESTAMP_H_INCLUDED
#define TIMEKEEPER_TIMESTAMP_H_INCLUDED
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
 * TimeStamp class.
 */
#include <chrono>
#include <ctime>
#include <string>

namespace UA_CoMP {
namespace Timekeeper {

/**
 * Provides wall-clock time stamp using the time call.
 * The time is that of the constructor call.
 */
class TimeStamp
{
public:
	/// Constructor marks the time for the time stamp.
	TimeStamp() : m_tp(std::chrono::system_clock::now()) {}

	/// Returns string with the time stamp after eliminating newline.
	std::string ToString() const
	{
		std::time_t t = std::chrono::system_clock::to_time_t(m_tp);
		std::string str = std::ctime(&t);
		str[str.length() - 1] = ' ';
		return str;
	}

	/// Returns time stamp as a time_t.
	std::time_t ToTimeT() const { return std::chrono::system_clock::to_time_t(m_tp); }

private:
	std::chrono::system_clock::time_point m_tp;
};

/**
 * TimeStamp helper inserts string representation in output stream.
 */
inline std::ostream& operator<<(std::ostream& os, TimeStamp t) { return (os << t.ToString()); }

} // namespace Timekeeper
} // namespace UA_CoMP

#endif // include guard
