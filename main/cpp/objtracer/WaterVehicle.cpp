/**
 * @file
 * Implementation for the class WaterVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/WaterVehicle.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {
using std::cout;
using std::endl;

/**
 * @return			None.
 * @exception		None.
 */
WaterVehicle::WaterVehicle() : Vehicle(), m_sinking(false) { COMP_MISC_MEMBER_TRACER; }

/**
 * @param		ori		Original to be copied.
 * @return				None.
 * @exception			None.
 */
WaterVehicle::WaterVehicle(const WaterVehicle& ori) : Vehicle(ori), m_sinking(ori.m_sinking)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @param		ori		Original to be moved.
 * @return				None.
 * @exception			None.
 */
WaterVehicle::WaterVehicle(WaterVehicle&& ori) : Vehicle(ori), m_sinking(std::move(ori.m_sinking))
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * Copy assignment operator has a guard against self-assignment.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
WaterVehicle& WaterVehicle::operator=(const WaterVehicle& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		Vehicle::operator=(rhs);
		m_sinking = rhs.m_sinking;
	}
	return *this;
}

/**
 * Move assignment operator has a guard against self-assignment.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
WaterVehicle& WaterVehicle::operator=(WaterVehicle&& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		Vehicle::operator=(rhs);
		m_sinking = std::move(rhs.m_sinking);
	}
	return *this;
}

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return				None.
 * @exception			None.
 */
WaterVehicle::~WaterVehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * @return				None.
 * @exception			None.
 */
void WaterVehicle::start_sinking()
{
	COMP_MISC_MEMBER_TRACER;
	m_sinking = true;
}

/**
 * @return				None.
 * @exception			None.
 */
void WaterVehicle::stop_sinking()
{
	COMP_MISC_MEMBER_TRACER;
	m_sinking = false;
}

/**
 * @return                  None.
 * @exception               None.
 */
void WaterVehicle::get_info() const
{
	COMP_MISC_MEMBER_TRACER;
	cout << "I'm a generic Water vehicle";
	if (m_sinking) {
		cout << " and I'm sinking!";
	}
	cout << endl;
}
}
