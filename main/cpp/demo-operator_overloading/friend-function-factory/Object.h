//
// Created by thomas on 13/11/2016.
//

#ifndef PROJECT_OBJECT_H
#define PROJECT_OBJECT_H

#include "../../demo-operator_overloading/friend-function-factory/Factory.h"

class Object
{
public:
	friend Object Factory::operator()();

	int printID() const { return id; }

private:
	Object(int id) : id{id} {} // Private constructor.
	const int id;
};

#endif // PROJECT_OBJECT_H
