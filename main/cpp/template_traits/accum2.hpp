#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accumtraits2.hpp"

template <typename T>
inline typename AccumulationTraits<T>::type accum(const T* beg, const T* end)
{
        using AccT = typename AccumulationTraits<T>::type;

        AccT total = AccT();
        while (beg != end) {
                total += *beg;
                ++beg;
        }
        return total;
}
