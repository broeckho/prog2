#include <iostream>

class Integer
{
public:
	Integer(int value) : value(value){};
	// Conversion operator, we can use this to convert to built in type
	operator int() const { return value; }

private:
	int value = 0;
};

int main()
{
	Integer anInteger(0);
	std::cout << "Integer to built in type int: " << int(anInteger) << std::endl;
}
