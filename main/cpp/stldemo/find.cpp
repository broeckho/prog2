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
 *  Copyright 2012, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Demo for find algorithm & ranges.
 */

// BEGIN_SNIPPET{FullSource}
#include "RandInt.h"
#include "Range.h"
#include <iomanip>
#include <list>

int main()
{
        std::list<int> c(15);
        RandInt r(7, static_cast<int>(c.size()));
        std::generate(c.begin(), c.end(), r);
        std::cout << make_range(c) << std::endl;
        auto it1 = find(c.begin(), c.end(), 14);
        auto it2 = find(it1, c.end(), 13);
        auto it3 = find(it1, it2, 11);
        std::cout << std::boolalpha << (it3 != it2) << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
