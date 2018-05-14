/**
 * @file
 * Implementation for the class Person.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "Person.h"
#include "tracer/tracer.h"

namespace ODemo {
using std::string;

Person::Person(std::string name) : m_name(std::move(name)) { COMP_MISC_MEMBER_TRACER; }

Person::~Person() { COMP_MISC_MEMBER_TRACER; }

string Person::get_name() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_name;
}
} // namespace ODemo
