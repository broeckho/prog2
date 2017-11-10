/**
 * @file.
 * Using the class template with default parameters.
 * @author J. Broeckhove, CoMP/UA - see copyright.txt
 */

// BEGIN_SNIPPET{FullSource}
#include "stack3.hpp"
#include <deque>
#include <iostream>

int main()
{
        try {
                Stack<int> intStack;
                Stack<double, std::deque<double>> dblStack;

                intStack.push(7);
                std::cout << intStack.top() << std::endl;

                dblStack.push(42.42);
                std::cout << dblStack.top() << std::endl;
                dblStack.pop();
        } catch (std::exception const& ex) {
                std::cerr << "Exception: " << ex.what() << std::endl;
                return EXIT_FAILURE;
        }
        return 0;
}
// END_SNIPPET{FullSource}
