/**
 * @file.
 * Template function usage with parameter deduction.
 * @author J. Broeckhove - see copyright.txt
 */

#include "max3.hpp"
#include <string>

int main()
{
        int a = 7;
        int b = 42;
        ::max(a, b);

        std::string s = "hey";
        std::string t = "you";
        ::max(s, t);

        int* p1 = &b;
        int* p2 = &a;
        ::max(p1, p2);

        char const* s1 = "David";
        char const* s2 = "Nico";
        ::max(s1, s2);

        return 0;
}
