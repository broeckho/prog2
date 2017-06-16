#include "../../demo-operator_overloading/functor-info/distance.h"
#include <iostream>

int main()
{
	Distance d(11, 10);
	std::cout << d(1, 5) << std::endl;
	return 0;
}
