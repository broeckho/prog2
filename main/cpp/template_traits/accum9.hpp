#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accumtraits4.hpp"
#include "sumpolicy3.hpp"

template <typename T, typename Policy = SumPolicy<>, typename Traits = AccumulationTraits<T>>
class Accum
{
public:
        using AccT = typename Traits::type;
        static AccT accum(const T* beg, const T* end)
        {
                AccT total = Traits::zero();
                while (beg != end) {
                        Policy::accumulate(total, *beg);
                        ++beg;
                }
                return total;
        }
};
