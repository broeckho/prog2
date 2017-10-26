/**
 * @file.
 * Stack with vector as container.
 * @author J. Broeckhove - see copyright.txt
 */

#include "stack6.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main()
{
        try {
                Stack<int> intStack;
                Stack<float> floatStack;
                intStack.push(42);
                intStack.push(7);
                floatStack.push(7.7);
                floatStack = intStack;
                std::cout << floatStack.top() << std::endl;
                floatStack.pop();
                std::cout << floatStack.top() << std::endl;
                floatStack.pop();
                std::cout << floatStack.top() << std::endl;
                floatStack.pop();
        } catch (std::exception const& ex) {
                std::cerr << "Exception: " << ex.what() << std::endl;
        }

        Stack<int, std::vector<int>> vStack;
        vStack.push(42);
        vStack.push(7);
        std::cout << vStack.top() << std::endl;
        vStack.pop();

        return 0;
}
