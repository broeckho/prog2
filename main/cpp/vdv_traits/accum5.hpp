/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUM5_HPP
#define INC_TRAITS_ACCUM5_HPP

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

#endif // INC_TRAITS_ACCUM5_HPP
