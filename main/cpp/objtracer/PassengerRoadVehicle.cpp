/**
 * @file
 * Implementation for the class PassenggerRoadVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/PassengerRoadVehicle.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {
using std::cout;
using std::endl;

/**
 * @return				None.
 * @param	numSeats	Amount of seats in the vehicle
 * @exception			None.
 */
PassengerRoadVehicle::PassengerRoadVehicle(int numSeats) : RoadVehicle(), m_capacity(numSeats), m_free(numSeats)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * Copy constructor for PassengerRoadVehicle.
 * @return				None.
 * @param		ori		Original to be copied.
 * @exception			None.
 */
PassengerRoadVehicle::PassengerRoadVehicle(const PassengerRoadVehicle& ori)
    : RoadVehicle(ori), m_capacity(ori.m_capacity), m_free(ori.m_free)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * Move constructor for PassengerRoadVehicle.
 * @return				None.
 * @param		ori		Original to be copied.
 * @exception			None.
 */
PassengerRoadVehicle::PassengerRoadVehicle(PassengerRoadVehicle&& ori)
    : RoadVehicle(std::move(ori)), m_capacity(std::move(ori.m_capacity)), m_free(std::move(ori.m_free))
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * Copy assignment for PassengerRoadVehicles.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
PassengerRoadVehicle& PassengerRoadVehicle::operator=(const PassengerRoadVehicle& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		RoadVehicle::operator=(rhs);
		m_capacity = rhs.m_capacity;
		m_free = rhs.m_free;
	}
	return *this;
}

/**
 * Move assignment for PassengerRoadVehicles.
 * @return				None.
 * @param		rhs		Right hand side in assignment.
 * @exception			None.
 */
PassengerRoadVehicle& PassengerRoadVehicle::operator=(PassengerRoadVehicle&& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		RoadVehicle::operator=(rhs);
		m_capacity = std::move(rhs.m_capacity);
		m_free = std::move(rhs.m_free);
	}
	return *this;
}

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return				None.
 * @exception			None.
 */
PassengerRoadVehicle::~PassengerRoadVehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * @return		bool		False when all seats are already taken,
 * true
 * otherwise.
 * @exception				None.
 */
bool PassengerRoadVehicle::add_passenger()
{
	COMP_MISC_MEMBER_TRACER;
	bool added = false;
	if (m_free > 0) {
		m_free--;
		added = true;
	}
	return added;
}

/**
 * @return		bool		false when there's no passenger to
 * remove,
 * true otherwise.
 * @exception				None.
 */
bool PassengerRoadVehicle::remove_passenger()
{
	COMP_MISC_MEMBER_TRACER;
	bool removed = false;
	if (m_free < m_capacity) {
		m_free++;
		removed = true;
	}
	return removed;
}

/**
 * @return 			int		Number of seats in the vehicle.
 * @exception				None.
 */
int PassengerRoadVehicle::get_capacity() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_capacity;
}

/**
 * @return			int		Number of free seats in vehicle.
 * @exception				None.
 */
int PassengerRoadVehicle::get_free() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_free;
}

/**
 * @return					None.
 * @exception				None.
 */
void PassengerRoadVehicle::get_info() const
{
	COMP_MISC_MEMBER_TRACER;
	cout << "I'm a PassengerRoadVehicle: #seats = " << m_capacity << ", #free seats = " << m_free << endl;
	RoadVehicle::get_info();
}
}
