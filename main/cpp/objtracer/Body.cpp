/**
 * @file
 * Implementation for the class Bicycle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "Body.h"
#include "tracer/tracer.h"
#include <iostream>
#include <utility>

namespace ODemo {
using namespace std;

Body::Body(std::string color) : m_color(color) { COMP_MISC_MEMBER_TRACER; }

/// Copy constructor
Body::Body(Body const& ori) : m_color(ori.m_color) { COMP_MISC_MEMBER_TRACER; }

/// Move constructor
Body::Body(Body&& ori) : m_color(std::move(ori.m_color)) { COMP_MISC_MEMBER_TRACER; }

/// Copy assignment
Body& Body::operator=(Body const& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_color = rhs.m_color;
	}
	return *this;
}

/// Move assignment
Body& Body::operator=(Body&& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_color = std::move(rhs.m_color);

		// Leave the argument in an indeterminate state.
		rhs.m_color = nullptr;
	}
	return *this;
}
}
