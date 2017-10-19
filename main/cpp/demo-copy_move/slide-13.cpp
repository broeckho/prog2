#include <iostream>

using namespace std;

class C
{
public:
	explicit C(int) {}
	C(const C&) { ++n; } // De copy-constructor heeft zichtbaar effect
	int get_count() const { return n; }

private:
	static int n;
};

int C::n = 0;

ostream& operator<<(ostream& os, const C& c)
{
	os << c.get_count() << endl;
	return os;
}

int main()
{
	C c1(42);           // Direct-initialisatie, calls C::C(42)
	cout << c1 << endl; // Print 0 als copy elision heeft opgetreden
	C c2(C(42));        // Copy-constructor, calls C::C( C::C(42) )
	cout << c2 << endl; // Print 0 als copy elision heeft opgetreden
	C c3(c2);           // Geen naamloze temporary
	cout << c3 << endl; // Print 1 want bij c3(c2) kan geen copy-elision optreden
	c3 = c1;
	cout << c3 << endl; // Assignment not involved.
}
