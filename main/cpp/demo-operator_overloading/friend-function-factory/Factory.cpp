#include "../../demo-operator_overloading/friend-function-factory/Factory.h"
#include "../../demo-operator_overloading/friend-function-factory/Object.h"

Object Factory::operator()()
{
        static int objectID = 0;
        createdObjectIds.push_back(objectID);
        return Object(objectID++);
}
