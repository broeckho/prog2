#include <iostream>

class Integer
{
public:
	explicit Integer(int value) : value(value){};
	int getValue() { return value; }

private:
	int value = 0;
};

// Uses an Integer
void useInteger(Integer anInteger){};

int main()
{

	// We must use is explicitly
	useInteger(Integer{0});

	// This will not compile if uncommented
	// useInteger(0);
}
