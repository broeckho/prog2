/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUM9_HPP
#define INC_TRAITS_ACCUM9_HPP

#include "accumtraits4.hpp"
#include "sumpolicy3.hpp"

template <typename T, typename Policy = SumPolicy<>, typename Traits = AccumulationTraits<T>>
class Accum
{
public:
        typedef typename Traits::AccT AccT;
        static AccT accum(T const* beg, T const* end)
        {
                AccT total = Traits::zero();
                while (beg != end) {
                        Policy::accumulate(total, *beg);
                        ++beg;
                }
                return total;
        }
};

#endif // INC_TRAITS_ACCUM9_HPP
