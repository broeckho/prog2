/**
 * @file.
 * Template function use with explicit parameters.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "max.hpp"
#include <iostream>

int main()
{
        int const i = 42;
        std::cout << max<int>(7, i) << std::endl;

        double const f1 = 3.4;
        double const f2 = -6.7;
        std::cout << max<double>(f1, f2) << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
