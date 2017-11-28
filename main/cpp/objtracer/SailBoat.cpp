/**
 * @file
 * Implementation for the class SailBoat.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/SailBoat.h"
#include "tracer/tracer.h"

namespace ODemo {

using namespace std;

SailBoat::SailBoat(string name) : WaterVehicle(), m_name(std::move(name)), m_sails_up(false)
{
        COMP_MISC_MEMBER_TRACER;
}

SailBoat::SailBoat(const SailBoat& ori) : WaterVehicle(ori), m_name(ori.m_name), m_sails_up(ori.m_sails_up)
{
        COMP_MISC_MEMBER_TRACER;
}

SailBoat::SailBoat(SailBoat&& ori) noexcept
    : WaterVehicle(std::move(ori)), m_name(std::move(ori.m_name)), m_sails_up(ori.m_sails_up)
{
        COMP_MISC_MEMBER_TRACER;
}

SailBoat& SailBoat::operator=(const SailBoat& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                WaterVehicle::operator=(rhs);
                m_name = rhs.m_name;
                m_sails_up = rhs.m_sails_up;
        }
        return *this;
}

SailBoat& SailBoat::operator=(SailBoat&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                WaterVehicle::operator=(rhs);
                m_name = std::move(rhs.m_name);
                m_sails_up = rhs.m_sails_up;
        }
        return *this;
}

SailBoat::~SailBoat() { COMP_MISC_MEMBER_TRACER; }

void SailBoat::info() const
{
        COMP_MISC_MEMBER_TRACER;
        string s {"I'm a sailboat named \"" + m_name + "\" and my sails are "};
        if (m_sails_up) {
                s.append("up.");
        } else {
                s.append("down.");
        }
        COMP_MISC_LOG_TRACER(s);
}

void SailBoat::move(double, vector<double>)
{
        COMP_MISC_MEMBER_TRACER;
        m_sails_up = true;
}

} // end of namespace
