/**
 * @file
 * Implementation for the class Bicycle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "Body.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {
using namespace std;

Body::Body(std::string color) : m_color(std::move(color)) { COMP_MISC_MEMBER_TRACER; }

/// Copy constructor
Body::Body(Body const& ori) : m_color(ori.m_color) { COMP_MISC_MEMBER_TRACER; }

/// Move constructor
Body::Body(Body&& ori) noexcept : m_color(std::move(ori.m_color)) { COMP_MISC_MEMBER_TRACER; }

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
Body& Body::operator=(Body&& rhs) noexcept
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_color = std::move(rhs.m_color);
		rhs.m_color = nullptr;
	}
	return *this;
}
}
