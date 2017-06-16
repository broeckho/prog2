/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits3.hpp"

template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T const* beg, T const* end)
{
	using AccT = typename AccumulationTraits<T>::AccT;

	AccT total = AccumulationTraits<T>::zero;
	while (beg != end) {
		total += *beg;
		++beg;
	}
	return total;
}

#endif // ACCUM_HPP
