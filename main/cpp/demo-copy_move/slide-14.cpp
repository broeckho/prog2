#include <iostream>

using namespace std;

struct C
{
        C() = default;

        // De copy-constructor heeft zichtbaar effect
        C(const C&) noexcept { cout << "Hello World!" << endl; }
};

void f()
{
        C c;
        throw C(c);
}

int main()
{
        try {
                f();
        } catch (C& c) {
        }
}
