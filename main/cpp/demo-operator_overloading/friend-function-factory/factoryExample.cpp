class Object;

Object Factory::operator()()
{
	static int objectID = 0;
	createdObjectIds.push_back(objectID);
	return Object(objectID++);
}
