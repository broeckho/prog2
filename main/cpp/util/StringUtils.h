#ifndef INC_STRINGUTILS_H
#define INC_STRINGUTILS_H
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
 * @file.
 * Conversion from or to string.
 * @author  J. Broeckhove, CoMP/UA, 2011.
 */

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>

namespace UA_CoMP {
namespace Util {

/**
 * String utilities.
 */
class StringUtils
{
public:
        /// Builds a value of type T representation from a string.
        template <typename T>
        inline static T FromString(std::string const& s)
        {
                std::stringstream ss(s);
                T t;
                ss >> t;
                return t;
        }

        /// Builds a string representation of a value of type T.
        template <typename T>
        inline static std::string ToString(T const& value)
        {
                std::stringstream ss;
                ss << value;
                return ss.str();
        }

        /// Builds a string with upper case characters only.
        static std::string ToUpper(std::string const& source)
        {
                auto upper = [](int c) -> int { return std::toupper(c); };
                std::string copy;
                std::transform(source.begin(), source.end(), std::back_inserter(copy), upper);
                return copy;
        }

        /// Trim characters at right end of string.
        static std::string TrimRight(std::string const& source, std::string const& t = " ")
        {
                std::string str = source;
                return str.erase(str.find_last_not_of(t) + 1);
        }

        /// Trim characters at left end of string.
        static std::string TrimLeft(std::string const& source, std::string const& t = " ")
        {
                std::string str = source;
                return str.erase(0, source.find_first_not_of(t));
        }

        /// Trim characters at both ends of string.
        static std::string Trim(std::string const& source, std::string const& t = " ")
        {
                std::string str = source;
                return TrimLeft(TrimRight(str, t), t);
        }
};

} // namespace Util
} // namespace UA_CoMP

#endif // end-of-include-guard
