/**
 * @file.
 * Calling overloaded function templates.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "max.hpp"

inline int const& max(int const& a, int const& b) { return a < b ? b : a; }

template <typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
	return max(max(a, b), c);
}

int main()
{
	::max(7, 42, 68);     // template for three arguments
	::max(7.0, 42.0);     // max<double> (argument deduction)
	::max('a', 'b');      // max<char> (argument deduction)
	::max(7, 42);         // nontemplate for two ints
	::max<>(7, 42);       // max<int> (argument deduction)
	::max<double>(7, 42); // max<double> (no argument deduction)

	return 0;
}
// END_SNIPPET{FullSource}
