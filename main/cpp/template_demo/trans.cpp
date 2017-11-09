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
 * Tranform sequences, using STL.
 */

// BEGIN_SNIPPET{FullSource}
#include "RandInt.h"
#include "Range.h"
#include <list>

namespace {

/**
 * Dummy functor for demo on using the STL transform algorithm.
 */
class Incrementor
{
public:
        explicit Incrementor(unsigned int n) : fNum(n) {}

        template <typename T>
        T operator()(T t)
        {
                for (unsigned int i = 1; i <= fNum; i++) {
                        t++;
                }
                return t;
        }

private:
        unsigned int fNum;
};

} // end-of-anonymous namespace

int main()
{
        std::vector<int> v(8);
        std::list<int> l(8);
        generate(v.begin(), v.end(), RandInt(3, static_cast<int>(v.size())));

        // Out of place transform
        Incrementor incr(2);
        transform(v.begin(), v.end(), l.begin(), incr);
        std::cout << make_range(v) << std::endl << make_range(l) << std::endl;

        // In place transform
        transform(v.begin(), v.end(), v.begin(), incr);
        std::cout << make_range(v) << std::endl;

        return 0;
}
// END_SNIPPET{FullSource}
