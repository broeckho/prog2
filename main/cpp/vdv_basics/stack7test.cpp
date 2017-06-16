/**
 * @file.
 * Stack with allocator and vector container.
 * @author J. Broeckhove - see copyright.txt
 */

#include "stack7.hpp"
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
		floatStack.push(7.7F);
		std::cout << floatStack.top() << std::endl;
		floatStack.pop();
		std::cout << floatStack.top() << std::endl;
		floatStack.pop();
		std::cout << floatStack.top() << std::endl;
		floatStack.pop();
	} catch (std::exception const& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	Stack<int, std::allocator<int>, std::vector> vStack;
	vStack.push(42);
	vStack.push(7);
	std::cout << vStack.top() << std::endl;
	vStack.pop();

	return 0;
}
