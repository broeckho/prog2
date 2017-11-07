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
 * Fill container with random values, first attempt.
 */

// BEGIN_SNIPPET{FullSource}
#include "../stldemo_1/Range.h"
#include <vector>

template <typename C>
void simpleRandInit(C& c, unsigned int seed)
{
        std::srand(seed);
        typename C::size_type size = c.size();
        for (auto it = c.begin(); it != c.end(); ++it) {
                *it = static_cast<typename C::value_type>(rand() % size);
        }
}

int main()
{
        std::vector<double> v(10);
        simpleRandInit(v, 3);
        std::cout << make_range(v) << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
