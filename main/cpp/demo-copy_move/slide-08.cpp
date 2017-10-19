#include <iostream>

using namespace std;

class X
{
public:
	X() { cout << "'Constructor'" << endl; }
	X(X&& o) noexcept { cout << "'Move'" << endl; }
};

//  X f(X & x) { return x; }          // !!!!!! Fout, copy is niet gedefiniëerd
//  (in return)
X g(X& x) { return std::move(x); } // OK, move is gedefiniëerd
X h(X x) { return std::move(x); }  // OK

int main()
{
	X a;
	X y = std::move(a);
	X b(g(y)); // OK
}
