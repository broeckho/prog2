/**
 * @file.
 * Using the stack class template.
 * @author J. Broeckhove, CoMP/UA - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "stack1.hpp"
#include <iostream>

int main()
{
        try {
                Stack<int> intStack;
                Stack<std::string> stringStack;

                intStack.push(7);
                std::cout << intStack.top() << std::endl;

                stringStack.push("hello");
                std::cout << stringStack.top() << std::endl;
                stringStack.pop();
        } catch (std::exception const& ex) {
                std::cerr << "Exception: " << ex.what() << std::endl;
                return EXIT_FAILURE;
        }
        return 0;
}
// END_SNIPPET{FullSource}
