/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "myfirst.hpp"
#include <iostream>
#include <typeinfo>

// implementation/definition of template
template <typename T>
void print_typeof(T const& x)
{
	std::cout << typeid(x).name() << std::endl;
}
