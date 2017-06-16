#ifndef INC_GOBELIJN_OBJTRACER_FREIGHTROADVEHICLE_H
#define INC_GOBELIJN_OBJTRACER_FREIGHTROADVEHICLE_H
/**
 * @file
 * Header for the FreightRoadVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */
#include "objtracer/RoadVehicle.h"

namespace ODemo {

/**
 * A FreightRoadVehicle is a Vehicle for transporting freight
 * and not people (aside from the driver).
 */
class FreightRoadVehicle : public RoadVehicle
{
public:
	/// Parametrized constructor, initializes freght capacity.
	FreightRoadVehicle(double freigthCapacity);

	/// Copy constructor.
	FreightRoadVehicle(const FreightRoadVehicle& ori);

	/// Move constructor.
	FreightRoadVehicle(FreightRoadVehicle&& ori);

	/// Copy assignment.
	FreightRoadVehicle& operator=(const FreightRoadVehicle& rhs);

	/// Move assignment.
	FreightRoadVehicle& operator=(FreightRoadVehicle&& rhs);

	/// Destructor
	virtual ~FreightRoadVehicle();

	/// Load freight onto the vehicle if capacity allows it.
	bool load(double freightWeight);

	/// Unload freight from the vehicle if enough is available.
	bool unload(double freightWeight);

	/// Get the freight capacity of this vehicle.
	double get_capacity() const;

	/// Get the currently used size of the load.
	double get_size() const;

	/// Display info about size of the load and capacity of the vehicle.
	virtual void get_info() const;

private:
	double m_capacity;
	double m_size;
};
}

#endif // end-of-include-guard
