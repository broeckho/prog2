class Integer
{
public:
	// As Member function
	Integer operator*(const Integer& other) { return Integer(value * other.value); }

	// Conversion operator, we can use this to convert to built in type
	// Used as: int i(anInteger);
	operator int() const { return m_val; }

private:
	int value = 0;
	friend Integer operator+(const Integer& a, const Integer& b);
};

// Via friends
Integer operator+(const Integer& a, const Integer& b) { return Integer(a.value + b.value); }

// Of via getters
Integer operator-(const Integer& a, const Integer& b) { return Integer(a.getValue() - b.getValue()); }

// Overloading non members, now we can specify a builtin type as the left operand.
Integer operator+(double a, Integer b) { return Integer( a + b.getValue()); }

// To complete the set of mixed operands.
Integer operator+(Integer a, double b) { return Integer( a.getValue() + b); }

// The Different types of operators: @type
Color Color::operator!() { return Color(255 - r, 255 - g, 255 - b); }

// type1 @ type2
bool Human::operator<(const Human& other) { return height < other.height; }

// Special: Literal
Integer operator""_I(unsigned long long int i) { return Integer(i); }

// Used as follows
int main() { Integer i = 3_I; }
