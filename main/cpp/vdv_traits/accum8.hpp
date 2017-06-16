/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUM8_HPP
#define INC_TRAITS_ACCUM8_HPP

#include "accumtraits4.hpp"
#include "sumpolicy2.hpp"

template <typename T, template <typename, typename> class Policy = SumPolicy, typename Traits = AccumulationTraits<T>>
class Accum
{
public:
	typedef typename Traits::type AccT;
	static AccT accum(T const* beg, T const* end)
	{
		AccT total = Traits::zero();
		while (beg != end) {
			Policy<AccT, T>::accumulate(total, *beg);
			++beg;
		}
		return total;
	}
};

#endif // INC_TRAITS_ACCUM8_HPP
