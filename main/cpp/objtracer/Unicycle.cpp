/**
 * @file
 * Implementation for the Unicycle class used to demo object aggregation
 * features.
 * @author J.Broeckhove  CoMP/UA
 */

#include "objtracer/Unicycle.h"
#include "tracer/tracer.h"

namespace ODemo {
using std::string;

/// straight initialization
Unicycle::Unicycle() : m_wheel(), m_speed(0.0), m_direction(0.0) { COMP_MISC_MEMBER_TRACER; }

/// Perform a deep copy of the engine and a shallow copy of the owner
Unicycle::Unicycle(Unicycle const& ori) : m_wheel(ori.m_wheel), m_speed(ori.m_speed), m_direction(ori.m_direction)
{
        COMP_MISC_MEMBER_TRACER;
}

/// Perform a deep copy of the engine and a shallow copy of the owner
Unicycle::Unicycle(Unicycle&& ori) noexcept
    : m_wheel(std::move(ori.m_wheel)), m_speed(ori.m_speed), m_direction(ori.m_direction)
{
        COMP_MISC_MEMBER_TRACER;
}

/// Copy constructor does what the synthesize constructor would do..
Unicycle& Unicycle::operator=(const Unicycle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                m_wheel = rhs.m_wheel;
                m_speed = rhs.m_speed;
                m_direction = rhs.m_direction;
        }
        return *this;
}

/// Move constructor does what the synthesize constructor would do..
Unicycle& Unicycle::operator=(Unicycle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                m_wheel = std::move(rhs.m_wheel);
                m_speed = rhs.m_speed;
                m_direction = rhs.m_direction;
        }
        return *this;
}

/// Nothing to do here..
Unicycle::~Unicycle() { COMP_MISC_MEMBER_TRACER; }

///
void Unicycle::accelerate(double speed)
{
        COMP_MISC_MEMBER_TRACER;
        m_speed = speed;
}

///
void Unicycle::brake(double speed)
{
        COMP_MISC_MEMBER_TRACER;
        m_speed = speed;
}

///
void Unicycle::turn(double degrees)
{
        COMP_MISC_MEMBER_TRACER;
        if (m_speed > 0.0) {
                m_direction += degrees;
        }
}

} // end_of_namespace ODemo
