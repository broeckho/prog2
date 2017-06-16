/**
 * @file.
 * Template function use with parameter deduction.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "max.hpp"
#include <iostream>
#include <string>

int main()
{
	int const i = 42;
	std::cout << ::max(7, i) << std::endl;

	std::string const s1 = "mathematics";
	std::string const s2 = "math";
	std::cout << ::max(s1, s2) << std::endl;

	/* Code below should trigger an error
	    float const f1 = 3.4F;
	double const f2 = -6.7;
	::max(f1, f2);
	*/

	return 0;
}
// END_SNIPPET{FullSource}
