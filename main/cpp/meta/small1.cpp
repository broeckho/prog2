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
 * Use of a type metafunction: first attempt.
 */
#include <iostream>

// BEGIN_SNIPPET{FullSource}
/// Primary template for compile-time selection based on size.
template <typename T1, typename T2, bool b = (sizeof(T1) < sizeof(T2))>
struct smaller_select
{
        using type = T1;
};

/// Specialization for bool==false.
template <typename T1, typename T2>
struct smaller_select<T1, T2, false>
{
        using type = T2;
};

int main()
{
        smaller_select<float, long int>::type haha = 0;
        std::cout << haha << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
