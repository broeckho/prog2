/**
 * @file
 * Implementation for the class RoadVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/RoadVehicle.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {
using std::cout;
using std::endl;
using std::vector;

/**
 * @return			None.
 * @exception		None.
 */
RoadVehicle::RoadVehicle() : LandVehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * Copy constructor for RoadVehicle.
 * @return				None.
 * @param		ori		Original to be copied.
 * @exception			None.
 */
RoadVehicle::RoadVehicle(const RoadVehicle& ori) : LandVehicle(ori) { COMP_MISC_MEMBER_TRACER; }

/**
 * Move constructor for RoadVehicle.
 * @return				None.
 * @param		ori		Original to be moved.
 * @exception			None.
 */
RoadVehicle::RoadVehicle(RoadVehicle&& ori) noexcept : LandVehicle(std::move(ori)) { COMP_MISC_MEMBER_TRACER; }

/**
 * Copy assignment has a guard against self-assignment.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
RoadVehicle& RoadVehicle::operator=(const RoadVehicle& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		LandVehicle::operator=(rhs);
	}
	return *this;
}

/**
 * Move assignment has a guard against self-assignment.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
RoadVehicle& RoadVehicle::operator=(RoadVehicle&& rhs) noexcept
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		LandVehicle::operator=(rhs);
	}
	return *this;
}

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return				None.
 * @exception			None.
 */
RoadVehicle::~RoadVehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * Implements a road-specific type of movement with wheels
 * (if you want other than wheels, implement your own move)
 */
void RoadVehicle::move(double speed, vector<double> direction)
{
	COMP_MISC_MEMBER_TRACER;
	cout << "RoadVehicle is moving with speed " << speed << " in direction" << endl;
	for (auto&& d: direction) {
		cout << d << endl;
	}
}

/**
 * @return				None.
 * @exception			None.
 */
void RoadVehicle::get_info() const
{
	COMP_MISC_MEMBER_TRACER;
	LandVehicle::get_info();
	cout << "I'm a generic Road vehicle" << endl;
}
}
