#pragma once
#include "../../demo-operator_overloading/friend-function-factory/Factory.h"

class Object
{
public:
        friend Object Factory::operator()();
        int printID() const { return id; }

private:
        explicit Object(int id) : id{id} {} // Private constructor.
        const int id;
};
