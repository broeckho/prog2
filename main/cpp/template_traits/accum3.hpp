#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accumtraits3.hpp"

template <typename T>
inline typename AccumulationTraits<T>::type accum(T const* beg, T const* end)
{
        using AccT = typename AccumulationTraits<T>::type;

        AccT total = AccumulationTraits<T>::value;
        while (beg != end) {
                total += *beg;
                ++beg;
        }
        return total;
}
