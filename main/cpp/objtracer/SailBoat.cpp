/**
 * @file
 * Implementation for the class SailBoat.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/SailBoat.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {
using std::string;
using std::cout;
using std::endl;
using std::vector;

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

void SailBoat::move(double speed, vector<double> direction)
{
        COMP_MISC_MEMBER_TRACER;
        m_sails_up = true;
        cout << "Sailboat is moving with speed " << speed << " in direction" << endl;
        for (const auto& d : direction) {
                cout << d << endl;
        }
}

void SailBoat::get_info() const
{
        COMP_MISC_MEMBER_TRACER;
        WaterVehicle::get_info();
        cout << "I'm a sailboat named \"" << m_name << "\" and my sails are ";
        if (m_sails_up) {
                cout << "up.";
        } else {
                cout << "down.";
        }
        cout << endl;
}
} // end of namespace
