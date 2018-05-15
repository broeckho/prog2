/**
 * @file.
 * Template function use with explicit parameters.
 * @author J. Broeckhove - see copyright.txt
 */

#include "max1.hpp"
#include <iostream>

int main()
{
        const int i = 42;
        std::cout << max<int>(7, i) << std::endl;

        const double f1 = 3.4;
        const double f2 = -6.7;
        std::cout << max<double>(f1, f2) << std::endl;

        const std::string s1 = "mathematics";
        const std::string s2 = "math";
        std::cout << ::max(s1, s2) << std::endl;

        return 0;
}
