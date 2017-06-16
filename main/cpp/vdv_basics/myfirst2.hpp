/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_BASICS_MYFIRST2_HPP
#define INC_BASICS_MYFIRST2_HPP

#include <iostream>
#include <typeinfo>

template <typename T>
void print_typeof(T const&);

template <typename T>
void print_typeof(T const& x)
{
	std::cout << typeid(x).name() << std::endl;
}

#endif // INC_BASICS_MYFIRST2_HPP
