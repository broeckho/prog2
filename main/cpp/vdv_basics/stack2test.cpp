/**
 * @file.
 * Client niet bewust van specialisatie.
 * @author J. Broeckhove - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "stack2.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
        try {
                Stack<std::string> stringStack;
                stringStack.push("hello");
                std::cout << stringStack.top() << std::endl;
                stringStack.pop();
        } catch (std::exception const& ex) {
                std::cerr << "Exception: " << ex.what() << std::endl;
                return EXIT_FAILURE; // exit program with ERROR status
        }
        return 0;
}
// END_SNIPPET{FullSource}
