/**
 * \authors Joost Akkermans, David Schotmans, Serge Knecht en Randy Paredis
 * \brief Onderstaand voorbeeld geeft aan dat de const_cast een 'undefined
 * behaviour' heeft. De const_cast<int*> zorgt ervoor dat toch de waarde
 * van const int a gewijzigd kan worden.
 * Wat blijkt is dat de compiler de cout van a als optimalisatie meteen
 * invult met de waarde 3, omdat deze er van uitgaat
 * dat de waarde van a const is en dus niet gewijzigd zal worden.
 **/

#include <iostream>
using namespace std;

int main()
{
	const int a = 3;
	auto b = const_cast<int*>(&a);
	*b = 5;
	cout << "Value of a: " << a << endl;
	cout << "Value of *b: " << *b << endl;
	return 0;
}
