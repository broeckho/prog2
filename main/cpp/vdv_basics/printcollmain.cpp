/**
 * @file.
 * Template function returns maximum.
 * @author J. Broeckhove - see copyright.txt
 */

#include "printcoll.hpp"
#include <vector>

int main()
{
        std::vector<int> v;
        v.push_back(42);
        v.push_back(13);
        v.push_back(7);
        printcoll(v);

        return 0;
}
