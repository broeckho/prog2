#include <iostream>
#include <utility>

using namespace std;

class X
{
public:
	X() { cout << "'Constructor'" << endl; }
	X(const X& o) { cout << "'Copy'" << endl; }
	X(X&& o) { cout << "'Move'" << endl; }
};

int main()
{
	X a;

	X b(a);
	X c = a;

	X d(std::move(b));
	X e = std::move(c);
}
