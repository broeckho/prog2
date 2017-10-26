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

/**
 * @return			None.
 * @exception		None.
 */
SailBoat::SailBoat(string name) : WaterVehicle(), m_name(std::move(name)), m_sails_up(false)
{
        COMP_MISC_MEMBER_TRACER;
}

/**
 * @return				None.
 * @param		ori		Original to be copied.
 * @exception			None.
 */
SailBoat::SailBoat(const SailBoat& ori) : WaterVehicle(ori), m_name(ori.m_name), m_sails_up(ori.m_sails_up)
{
        COMP_MISC_MEMBER_TRACER;
}

/**
 * @return				None.
 * @param		ori		Original to be moved.
 * @exception			None.
 */
SailBoat::SailBoat(SailBoat&& ori) noexcept
    : WaterVehicle(std::move(ori)), m_name(std::move(ori.m_name)), m_sails_up(ori.m_sails_up)
{
        COMP_MISC_MEMBER_TRACER;
}

/**
 * Copy assignment has a guard against self-assignment.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
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

/**
 * Move assignment has a guard against self-assignment.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
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

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return				None.
 * @exception			None.
 */
SailBoat::~SailBoat() { COMP_MISC_MEMBER_TRACER; }

/**
 * @return				None.
 * @exception			None.
 */
void SailBoat::move(double speed, vector<double> direction)
{
        COMP_MISC_MEMBER_TRACER;
        m_sails_up = true;
        cout << "Sailboat is moving with speed " << speed << " in direction" << endl;
        for (auto&& d : direction) {
                cout << d << endl;
        }
}

/**
 * @return                  None.
 * @exception               None.
 */
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
}
