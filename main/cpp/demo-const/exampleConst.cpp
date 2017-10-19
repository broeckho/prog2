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
	A() = default;

	void f() const { std::cout << "Using f() const: value i = " << i << std::endl; }

	void f()
	{
		i++;
		std::cout << "Using f(): value i = " << i << std::endl;
	}

	int i = 0;
};

int main()
{
	A a;
	a.f();

	const A b;
	b.f();
	return 0;
}
