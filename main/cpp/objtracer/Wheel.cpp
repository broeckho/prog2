/**
 * @file
 * Implementation for the Wheel class.
 * @author J.Broeckhove  CoMP/UA
 */

#include "Wheel.h"
#include "tracer/tracer.h"

namespace ODemo {
using std::string;

/**
 * @return                  None.
 */
Wheel::Wheel() : m_speed(0.0), m_rotating(false) { COMP_MISC_MEMBER_TRACER; }

/**
 * @param          ori      Original to be copied.
 * @return                  None.
 */
Wheel::Wheel(const Wheel& ori) : m_speed(ori.m_speed), m_rotating(ori.m_rotating) { COMP_MISC_MEMBER_TRACER; }

/**
 * @param          ori      Original to be moved.
 * @return                  None.
 */
Wheel::Wheel(Wheel&& ori) noexcept: m_speed(ori.m_speed), m_rotating(ori.m_rotating)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * Copy assignment operator has a guard against self-assignment.
 * @param          rhs      Right hand side in assignment.
 * @return                  None.
 */
Wheel& Wheel::operator=(Wheel const& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_speed = rhs.m_speed;
		m_rotating = rhs.m_rotating;
	}
	return *this;
}

/**
 * Move assignment operator has a guard against self-assignment.
 * @param          rhs      Right hand side in assignment.
 * @return                  None.
 */
Wheel& Wheel::operator=(Wheel&& rhs) noexcept
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_speed = rhs.m_speed;
		m_rotating = rhs.m_rotating;
	}
	return *this;
}

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return          None.
 */
Wheel::~Wheel() { COMP_MISC_MEMBER_TRACER; }

/**
 * @return         None.
 */
void Wheel::start()
{
	COMP_MISC_MEMBER_TRACER;
	if (!m_rotating) {
		m_rotating = true;
	}
}

/**
 * @return          None.
 */
void Wheel::stop()
{
	COMP_MISC_MEMBER_TRACER;
	if (m_rotating) {
		m_rotating = false;
	}
}

/**
 * @return          True is the wheels are turning, false otherwise.
 */
bool Wheel::is_rotating() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_rotating;
}

} // end of namespace ODemo
