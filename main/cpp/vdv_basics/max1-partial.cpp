/**
 * @file.
 * Partial parameter deduction.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include <iostream>

template <typename U, typename T>
inline U max(T const& a, T const& b)
{
        return a < b ? b : a;
}

int main()
{
        // U=double explicit, T=int deduced
        std::cout << ::max<double>(7, 12) << std::endl;
        return 0;
}
// END_SNIPPET{FullSource}
