#include <iostream>

using namespace std;

int n = 0;

struct C
{
	C(int) {}

	// De copy-constructor heeft zichtbaar effect
	C(const C&) { ++n; }
};

int main()
{
	C c1(42);          // Direct-initialisatie, calls C::C(42)
	C c2(C(42));       // Copy-constructor, calls C::C( C::C(42) )
	cout << n << endl; // Print 0 als copy elision heeft opgetreden
	C c3(c2);          // Geen naamloze temporary
	cout << n << endl; // Print 1 want bij c3(c2) kan geen
			   // copy-elision optreden
}
