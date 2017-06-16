#include <iostream>

using namespace std;

struct C
{
	C() {}

	// De copy-constructor heeft zichtbaar effect
	C(const C&) { cout << "Hello World!" << endl; }
};

void f()
{
	C c;
	throw c;
}

int main()
{
	try {
		f();
	} catch (C c) {
	}
}
