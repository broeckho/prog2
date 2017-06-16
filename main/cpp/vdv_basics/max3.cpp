/**
 * @file.
 * Partial ordering of specialisation of function templates.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "max.hpp"

// maximum of 2 pointers
template <typename T>
inline T* const& max(T* const& a, T* const& b)
{
	return *a < *b ? b : a;
}

int main()
{
	int a = 7;
	int b = 42;
	::max(a, b);
	int* p1 = &b;
	int* p2 = &a;
	::max(p1, p2);

	return 0;
}
// END_SNIPPET{FullSource}
