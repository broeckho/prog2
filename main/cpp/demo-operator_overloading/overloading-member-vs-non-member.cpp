#include <iostream>

class Integer
{
public:
	explicit Integer(int value) : value(value){};

	// As Member function
	Integer operator*(const Integer& other)
	{
		std::cout << "Overloading as Member" << std::endl;
		return Integer(value * other.value);
	}

	int getValue() const { return value; }

private:
	int value = 0;
	friend Integer operator+(const Integer& a, const Integer& b);
};

// Via friends
Integer operator+(const Integer& a, const Integer& b)
{
	std::cout << "Overloading as friend function" << std::endl;
	return Integer(a.value + b.value);
}

// Of via getters
Integer operator-(const Integer& a, const Integer& b)
{
	std::cout << "Overloading using getters" << std::endl;
	return Integer(a.getValue() - b.getValue());
}

int main()
{
	Integer a(5);
	Integer b(3);

	std::cout << "a * b: " << std::endl;
	a* b;

	std::cout << "a + b: " << std::endl;
	a + b;

	std::cout << "a - b: " << std::endl;
	a - b;
}
