/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits4.hpp"

template <typename T>
inline typename AccumulationTraits<T>::type accum(T const* beg, T const* end)
{
	using AccT = typename AccumulationTraits<T>::type;

	AccT total = AccumulationTraits<T>::zero();
	while (beg != end) {
		total += *beg;
		++beg;
	}
	return total;
}

#endif // ACCUM_HPP
