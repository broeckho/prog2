/**
 * \authors Joost Akkermans, David Schotmans, Serge Knecht en Randy Paredis
 * \brief Onderstaand voorbeeld geeft weer dat de impliciete assignment
 * operator door de compiler verwijderd wordt, aangezien er een const data
 * member aanwezig is in de klasse-declaratie.
 * Indien je deze code zou trachten te compileren, dan zal de compiler
 * normaliter een error geven omdat je de impliciet verwijderde assignment
 * operator tracht te gebruiken.
 * Indien je de code opnieuw compileert waarbij je de custom assignment
 * operator uit de comments haalt, dan zal de compiler geen errors geven.
 **/

#include <iostream>

using namespace std;

class Test
{
public:
	Test(int val) : i(val) {}

	Test(const Test& that) : i(that.i) {}

	// Test& operator=(const Test & that) {
	// 	int * var = const_cast<int*>(&i);
	// 	*var = that.i;
	// 	return *this;
	// }

	int getValue() const { return i; }

private:
	const int i; // const data member verwijderd impliciete assignment operator
};

int main()
{
	Test t(3);
	Test b(2);
	cout << "b.i = " << b.getValue() << "\n";

	// b = t;	       // !!!!!! assignment zonder custom assignment operator
	// zal
	// een compile error geven

	cout << "b.i = " << b.getValue() << "\n";
	return 0;
}
