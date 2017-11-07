#include <iostream>

using namespace std;

class Integer
{
public:
        explicit Integer(int i) : m_value(i) {}

private:
        friend ostream& operator<<(ostream& os, const Integer& integer);

private:
        int m_value;
};

ostream& operator<<(ostream& os, const Integer& integer)
{
        os << integer.m_value;
        return os;
}

int main()
{
        const Integer i{5};
        cout << "Integer is: " << i << endl;
}
