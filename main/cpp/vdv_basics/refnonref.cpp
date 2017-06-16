/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include <iostream>
#include <typeinfo>

template <typename T>
void ref(T const& x)
{
	std::cout << "x in ref(T const&): " << typeid(x).name() << '\n';
}

template <typename T>
void nonref(T x)
{
	std::cout << "x in nonref(T):     " << typeid(x).name() << '\n';
}

int main()
{
	ref("hello");
	nonref("hello");
	return 0;
}
