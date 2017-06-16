#include <iostream>
#include <utility>

using namespace std;

class X
{
public:
	X() { cout << "'Constructor'" << endl; }
	X(X&& o) { cout << "'Move'" << endl; }
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

	//  X c(h(a));                // !!!!!! Fout, copy constructor van X niet
	//  gedefiniëerd
	X d(h(std::move(a))); // Wel OK, geeft rvalue aan g
}
