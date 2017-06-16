#ifndef INC_GOBELIJN_OBJTRACER_PASSENGERROADVEHICLE_H
#define INC_GOBELIJN_OBJTRACER_PASSENGERROADVEHICLE_H
/**
 * @file
 * Header for PassengerRoadVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/RoadVehicle.h"

namespace ODemo {

/**
 * A PassengerRoadVehicle transports one or more passengers.
 */
class PassengerRoadVehicle : public RoadVehicle
{
public:
	/// Parametrized constructor, initializes number of seats.
	PassengerRoadVehicle(int numSeats);

	/// Copy constructor.
	PassengerRoadVehicle(PassengerRoadVehicle const& ori);

	/// Move constructor.
	PassengerRoadVehicle(PassengerRoadVehicle&& ori);

	/// Copy assignment.
	PassengerRoadVehicle& operator=(PassengerRoadVehicle const& rhs);

	/// Move assignment.
	PassengerRoadVehicle& operator=(PassengerRoadVehicle&& rhs);

	/// Destructor.
	virtual ~PassengerRoadVehicle();

	/// Take an additional passenger on board, if possible.
	bool add_passenger();

	/// Remove a passenger, if possible.
	bool remove_passenger();

	/// Return the number of seats on the vehicle.
	int get_capacity() const;

	/// Return the number of seats still free.
	int get_free() const;

	/// Display identification info.
	virtual void get_info() const;

private:
	int m_capacity;
	int m_free;
};
}

#endif // end-of-include-guard
