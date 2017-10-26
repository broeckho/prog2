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
 * Use of a numeric metafunction.
 */

#include <iostream>

// BEGIN_SNIPPET{FullSource}
/** Recursive template for compile-time power of 2*/
template <int N>
struct power
{
        static int constexpr value = 2 * power<N - 1>::value;
};

/** Ends recursive instantiation */
template <>
struct power<0>
{
        static int constexpr value = 1;
};

int main()
{
        int p = power<6>::value;
        int a[power<2>::value] = {0, 0, 0, 0};
        std::cout << p << "  " << a[0] << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
