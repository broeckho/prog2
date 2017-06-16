//
// Created by thomas on 13/11/2016.
//

#include "../../demo-operator_overloading/friend-function-factory/Factory.h"
#include "../../demo-operator_overloading/friend-function-factory/Object.h"
#include <iostream>

int main()
{
	Factory factory;

	Object a = factory();

	Object b = factory();

	Object c = factory();

	std::cout << "ID van a: " << a.printID() << std::endl
		  << "ID van b: " << b.printID() << std::endl
		  << "ID van c: " << c.printID() << std::endl;
}
