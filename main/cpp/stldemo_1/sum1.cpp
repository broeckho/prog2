/*
// *  This file is part of the gobelijn software.
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
 *  Copyright 2012, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Sum elements of container, first attempt.
 */

// BEGIN_SNIPPET{FullSource}
#include "../stldemo_1/Range.h"
#include <list>
#include <vector>

template <typename C>
typename C::value_type sum(C const& c)
{
        typename C::value_type val = typename C::value_type();
        for (auto it = c.cbegin(); it != c.cend(); ++it) {
                val += *it;
        }
        return val;
}

int main()
{
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::cout << make_range(v) << " sum: " << sum(v) << std::endl;
        std::list<double> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        std::cout << make_range(l) << " sum: " << sum(l) << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
