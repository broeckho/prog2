/**
 * @file.
 * Demonstrate use of member function templates.
 * @author J. Broeckhove - see copyright.txt
 */

#include "stack5.hpp"
#include <iostream>

int main()
{
        try {
                Stack<int> intStack;
                Stack<double> doubleStack;
                intStack.push(42);
                intStack.push(7);
                doubleStack.push(7.7);
                doubleStack = intStack;
                std::cout << doubleStack.top() << std::endl;
                doubleStack.pop();
        } catch (std::exception const& ex) {
                std::cerr << "Exception: " << ex.what() << std::endl;
                return EXIT_FAILURE;
        }
        return 0;
}
