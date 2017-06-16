/**
 * @file
 * Implementation of the FreightRoadVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "FreightRoadVehicle.h"
#include "tracer/tracer.h"
#include <iostream>
#include <utility>

namespace ODemo {
using std::cout;
using std::endl;

/**
 * @param	freightCapacity		Capacity of the vehicle
 * @return						None.
 * @exception					None.
 */
FreightRoadVehicle::FreightRoadVehicle(double freightCapacity) : RoadVehicle(), m_capacity(freightCapacity), m_size(0)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @return				None.
 * @param		ori		Original to be copied.
 * @exception			None.
 */
FreightRoadVehicle::FreightRoadVehicle(const FreightRoadVehicle& ori)
    : RoadVehicle(ori), m_capacity(ori.m_capacity), m_size(ori.m_size)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @return				None.
 * @param		ori		Original to be moved.
 * @exception			None.
 */
FreightRoadVehicle::FreightRoadVehicle(FreightRoadVehicle&& ori)
    : RoadVehicle(ori), m_capacity(std::move(ori.m_capacity)), m_size(std::move(ori.m_size))
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @return				None.
 * @param		rhs		Right hand side in copy assignment.
 * @exception			None.
 */
FreightRoadVehicle& FreightRoadVehicle::operator=(const FreightRoadVehicle& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		RoadVehicle::operator=(rhs);
		m_capacity = rhs.m_capacity;
		m_size = rhs.m_size;
	}
	return *this;
}

/**
 * @return				None.
 * @param		rhs		Right hand side in move assignment.
 * @exception			None.
 */
FreightRoadVehicle& FreightRoadVehicle::operator=(FreightRoadVehicle&& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		RoadVehicle::operator=(rhs);
		m_capacity = std::move(rhs.m_capacity);
		m_size = std::move(rhs.m_size);

		// Leave the argument in an indeterminate state.
		rhs.m_capacity = 0.0;
		rhs.m_size = 0.0;
	}
	return *this;
}

/**
 * Destructor has to be virtual because we are in an inheritance hierarchy.
 * @return				None.
 * @exception			None.
 */
FreightRoadVehicle::~FreightRoadVehicle() { COMP_MISC_MEMBER_TRACER; }

/**
 * Load freight if capacity of vehicle allows it.
 * @param		weight		Amount of freight to add_passenger
 * @return		bool		Indicates whether freight got loaded or
 * not.
 * @exception				None.
 */
bool FreightRoadVehicle::load(double weight)
{
	COMP_MISC_MEMBER_TRACER;
	bool loaded = false;
	if (weight <= (m_capacity - m_size)) {
		m_size += weight;
		loaded = true;
	}
	return loaded;
}

/**
 * @param		weight		Amount of freight to remove
 * @return		bool		True when freight is unloaded, false
 * otherwise.
 * @exception				None.
 */
bool FreightRoadVehicle::unload(double weight)
{
	COMP_MISC_MEMBER_TRACER;
	bool unloaded = false;
	if (weight <= m_size) {
		m_size -= weight;
		unloaded = true;
	}
	return unloaded;
}

/**
 * @return	double	Total amount of freight this vehicle can carry.
 * @exception		None.
 */
double FreightRoadVehicle::get_capacity() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_capacity;
}

/**
 * @return	double	Amount of currently used freight capacity.
 * @exception		None.
 */
double FreightRoadVehicle::get_size() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_size;
}

/**
 * @return			None.
 * @exception		None.
 */
void FreightRoadVehicle::get_info() const
{
	COMP_MISC_MEMBER_TRACER;
	cout << "I'm a FreightRoadVehicle: capacity = " << m_capacity << ", used capacity = " << m_size << endl;
	RoadVehicle::get_info();
}
}
