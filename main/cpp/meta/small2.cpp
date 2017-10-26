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
 * Apply the smaller template.
 */

// BEGIN_SNIPPET{FullSource}
#include "smaller.h"

namespace {

/**
 * Demo on compile-time type selection.
 */
template <typename T1, typename T2>
class pack_for_file_storage
{
public:
        using pack_type = typename smaller<T1, T2>::type;

public:
        pack_for_file_storage() = default;
        void pack(T1 t1){};
        void pack(T2 t2){};
        pack_type peek(unsigned int i) const { return fInfo[i]; }

private:
        pack_type fInfo[100000];
};

} // anonnymous namespace

int main()
{
        pack_for_file_storage<float, long> pp;
        pack_for_file_storage<float, long>::pack_type p;
        p = pp.peek(3);
        //...
        return 0;
}
// END_SNIPPET{FullSource}
