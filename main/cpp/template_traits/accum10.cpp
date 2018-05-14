/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accum10.hpp"
#include <iostream>

int main()
{
        // create array of 5 integer values and print average value
        int num[] = {1, 2, 3, 4, 5};
        std::cout << "the average value of the integer values is " << accum(&num[0], &num[5]) / 5 << '\n';

        // create array of character values and (try to) print average character value
        char name[] = "templates";
        int length = sizeof(name) - 1;
        std::cout << "the average value of the characters in \"" << name << "\" is "
                  << accum(&name[0], &name[length]) / length << '\n';

        return 0;
}
