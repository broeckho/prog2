#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accumtraits4.hpp"

template <typename T, typename AT = AccumulationTraits<T>>
class Accum
{
public:
        static typename AT::type accum(T const* beg, T const* end)
        {
                typename AT::type total = AT::zero();
                while (beg != end) {
                        total += *beg;
                        ++beg;
                }
                return total;
        }
};

