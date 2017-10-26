#include <iostream>

using namespace std;

class Y
{
public:
        // Copy en move constructors impliciet gedefiniëerd
        explicit Y(string s) : m_s(std::move(s)) {}
        void print() { cout << "'" << m_s << "'" << endl; }

private:
        std::string m_s;
};

int main()
{
        Y a("Foo");
        Y b("Bar");

        Y x = a;
        Y y = std::move(b);

        a.print();
        x.print();
        y.print();
}
