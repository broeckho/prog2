/**
 * \authors Joost Akkermans, David Schotmans, Serge Knecht en Randy Paredis
 * \brief Onderstaand voorbeeld illustreert het principe dat een const
 * altijd het pad dat const is bewandeld. Als deze code uitgevoerd zal worden,
 * is te zien dat a.f() de non-const f() aanroept en de b.f() de const functie
 * aanroept.
 **/

#include <iostream>

class A
{
public:
        A(int i) : m_i(i){};

        void f() const { std::cout << "Using f() const: value i = " << m_i << std::endl; }

        void f() { std::cout << "Using f(): value i = " << ++m_i << std::endl; }

private:
        int m_i = 0;
};

int main()
{
        A a(1);
        a.f();

        const A b(1);
        b.f();
        return 0;
}
