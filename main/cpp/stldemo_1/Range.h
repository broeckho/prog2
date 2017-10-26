#ifndef GOBELIJN_STLDEMO_RANGE_H
#define GOBELIJN_STLDEMO_RANGE_H
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
 * Range (see also boost Range library)
 */

// BEGIN_SNIPPET{FullSource}
#include <iostream>

/// Range needs to be a specific type so we can overload some
/// operators (e.g. operator<<) specifically for ranges but not
/// for pairs in general
template <typename Iter>
struct Range : public std::pair<Iter, Iter>
{
        Range(Iter it1, Iter it2) : std::pair<Iter, Iter>(it1, it2){};
};

template <typename Iter>
Range<Iter> make_range(Iter it1, Iter it2)
{
        return Range<Iter>(it1, it2);
}

template <typename Cont>
Range<typename Cont::const_iterator> make_range(Cont const& c)
{
        return Range<typename Cont::const_iterator>(c.begin(), c.end());
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::pair<T, U> const& p)
{
        operator<<(out.operator<<(p.first), " - ");
        (out.operator<<(p.second)).operator<<(std::endl);
        return out;
}

template <typename Iter>
std::ostream& operator<<(std::ostream& out, Range<Iter> r)
{
        for (Iter it = r.first; it != r.second; ++it) {
                out << " " << *it;
        }
        return out;
}
// END_SNIPPET{FullSource}

#endif // end-of-include-guard
