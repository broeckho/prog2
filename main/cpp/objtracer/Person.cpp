/**
 * @file
 * Implementation for the class Person.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "Person.h"
#include "tracer/tracer.h"

namespace ODemo {
using std::string;

/**
 * Parameterized constructor of a Person.
 * @param name The name of the person
 */
Person::Person(std::string name) : m_name(name) { COMP_MISC_MEMBER_TRACER; }

/**
 * Copy-constructor constructor of a Person is private.
 * (cloning people doesn't work as of now)
 */
Person::Person(const Person& ori) : m_name(ori.m_name) { COMP_MISC_MEMBER_TRACER; }

/**
 * Assignment operator of a Person is private.
 * (cloning people doesn't work as of now)
 */
Person& Person::operator=(const Person& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_name = rhs.m_name;
	}
	return *this;
}

/**
 * Destructor of a person
 */
Person::~Person() { COMP_MISC_MEMBER_TRACER; }

/**
 * Gets the name of this person
 */
string Person::get_name() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_name;
}
}
