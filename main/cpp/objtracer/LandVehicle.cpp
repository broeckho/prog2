/**
 * @file
 * Implementation for the class LandVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/LandVehicle.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {
using std::vector;
using std::cout;
using std::endl;

/**
 * @return			None.
 * @exception		None.
 */
LandVehicle::LandVehicle() : Vehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * Copy constructor for LandVehicle.
 * @return				None.
 * @param		ori		Original to be copied.
 * @exception			None.
 */
LandVehicle::LandVehicle(const LandVehicle& ori) : Vehicle(ori) { COMP_MISC_MEMBER_TRACER; }

/**
 * Move constructor for LandVehicle.
 * @return				None.
 * @param		ori		Original to be moved.
 * @exception			None.
 */
LandVehicle::LandVehicle(LandVehicle&& ori) noexcept : Vehicle(ori) { COMP_MISC_MEMBER_TRACER; }

/**
 * Copy assignment operator for LandVehicle.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
LandVehicle& LandVehicle::operator=(const LandVehicle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                Vehicle::operator=(rhs);
        }
        return *this;
}

/**
 * Move assignment operator for LandVehicle.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
LandVehicle& LandVehicle::operator=(LandVehicle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                Vehicle::operator=(rhs);
        }
        return *this;
}

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return				None.
 * @exception			None.
 */
LandVehicle::~LandVehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * @return              None.
 * @exception			None.
 */
void LandVehicle::get_info() const
{
        COMP_MISC_MEMBER_TRACER;
        cout << "I'm a generic Land vehicle" << endl;
}
}
