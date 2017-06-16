#include <iostream>
#include <utility>

using namespace std;

class Y
{
public:
	// Copy en move constructors impliciet gedefiniëerd
	Y(string s) : m_s(s) {}
	void print() { cout << "'" << m_s << "'" << endl; }

private:
	string m_s;
};

int main()
{
	Y a("Foo"), b("Bar");

	Y x = a;
	Y y = std::move(b);

	a.print();
	b.print();
	x.print();
	y.print();
}
