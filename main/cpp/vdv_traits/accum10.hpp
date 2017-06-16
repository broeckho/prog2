/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUM10_HPP
#define INC_TRAITS_ACCUM10_HPP

#include <iterator>

template <typename Iter>
inline typename std::iterator_traits<Iter>::value_type accum(Iter start, Iter end)
{
	typedef typename std::iterator_traits<Iter>::value_type VT;

	VT total = VT(); // assume VT() actually creates a zero value
	while (start != end) {
		total += *start;
		++start;
	}
	return total;
}

#endif // INC_TRAITS_ACCUM10_HPP
