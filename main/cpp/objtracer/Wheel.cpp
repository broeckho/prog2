/**
 * @file
 * Implementation for the Wheel class.
 * @author J.Broeckhove  CoMP/UA
 */

#include "Wheel.h"
#include "tracer/tracer.h"

namespace ODemo {
using std::string;

Wheel::Wheel() : m_speed(0.0), m_rotating(false) { COMP_MISC_MEMBER_TRACER; }

Wheel::Wheel(const Wheel& ori) : m_speed(ori.m_speed), m_rotating(ori.m_rotating) { COMP_MISC_MEMBER_TRACER; }

Wheel::Wheel(Wheel&& ori) noexcept : m_speed(ori.m_speed), m_rotating(ori.m_rotating) { COMP_MISC_MEMBER_TRACER; }

Wheel& Wheel::operator=(Wheel const& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                m_speed = rhs.m_speed;
                m_rotating = rhs.m_rotating;
        }
        return *this;
}

Wheel& Wheel::operator=(Wheel&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                m_speed = rhs.m_speed;
                m_rotating = rhs.m_rotating;
        }
        return *this;
}

Wheel::~Wheel() { COMP_MISC_MEMBER_TRACER; }

void Wheel::start()
{
        COMP_MISC_MEMBER_TRACER;
        if (!m_rotating) {
                m_rotating = true;
        }
}

void Wheel::stop()
{
        COMP_MISC_MEMBER_TRACER;
        if (m_rotating) {
                m_rotating = false;
        }
}

bool Wheel::is_rotating() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_rotating;
}

} // namespace ODemo
