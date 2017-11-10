#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */


#include <iterator>

template <typename Iter>
inline typename std::iterator_traits<Iter>::value_type accum(Iter start, Iter end)
{
        typedef typename std::iterator_traits<Iter>::value_type VT;

        VT total = VT(); // assume VT() actually creates a zero value
        while (start != end) {
                total += *start;
                ++start;
        }
        return total;
}

