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
 * Sum the elements of container, using STL.
 */

// BEGIN_SNIPPET{FullSource}
#include "../stldemo_1/Range.h"
#include <algorithm>
#include <vector>

template <typename T>
class Accumulator
{
public:
        Accumulator(T t = T()) : fAccumulator(t) {}

        T operator()(T t) { return (fAccumulator += t); }

        T operator()() const { return fAccumulator; }

private:
        T fAccumulator;
};

int main()
{
        std::vector<int> v(3);
        Accumulator<int> a;
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        a = std::for_each(v.begin(), v.end(), a);
        std::cout << make_range(v) << " sum: " << a() << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
