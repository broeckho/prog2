#ifndef INC_GOBELIJN_OBJTRACER_PERSON_H_
#define INC_GOBELIJN_OBJTRACER_PERSON_H_
/**
 * @file
 * Header for the class Person.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include <string>

namespace ODemo {

/**
 * A fairly simple class for Person.
 * Person does not model the concept Assignable (cfr. Austern,
 * Generic Programming and the STL, Chapter 6).
 */
class Person
{
public:
	/// Constructor initializes the name of the person.
	Person(std::string name);

	/// Destructor.
	virtual ~Person();

	/// Return the persons name.
	std::string get_name() const;

private:
	/// Disallow copy-construction and move-construction of people:
	Person(const Person&);
	Person(Person&&);
	/// Disallow copy-assignment and move-assignment of people:
	Person& operator=(const Person&);
	Person& operator=(Person&&);

	std::string m_name;
};
}

#endif // end-of-include-guard
