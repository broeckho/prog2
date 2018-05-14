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
#include <cstddef>
#include <vector>

using namespace std;

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
        explicit pack_for_file_storage(size_t s) { m_data.resize(s); };
        void pack(T1 t1, size_t i) { m_data[i] = static_cast<pack_type>(t1); }
        void pack(T2 t2, size_t i) { m_data[i] = static_cast<pack_type>(t2); };
        pack_type peek(size_t i) const { return m_data[i]; }

private:
        vector<pack_type> m_data;
};

} // namespace

int main()
{
        pack_for_file_storage<float, long> pp{100};
        pack_for_file_storage<float, long>::pack_type p;
        p = pp.peek(3);
        pp.pack(5.0f, 4);
        pp.pack(1l, 6);
        pp.pack(p, 1);
        //...
        return 0;
}
// END_SNIPPET{FullSource}
