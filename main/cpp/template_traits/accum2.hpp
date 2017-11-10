#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accumtraits2.hpp"

template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T const* beg, T const* end)
{
        typedef typename AccumulationTraits<T>::AccT AccT;

        AccT total = AccT();
        while (beg != end) {
                total += *beg;
                ++beg;
        }
        return total;
}

