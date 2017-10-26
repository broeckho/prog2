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
Person::Person(std::string name) : m_name(std::move(name)) { COMP_MISC_MEMBER_TRACER; }

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
