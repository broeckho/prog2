#ifndef INC_GOBELIJN_OBJTRACER_LANDVEHICLE_H
#define INC_GOBELIJN_OBJTRACER_LANDVEHICLE_H
/**
 * @file
 * Header for the LandVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/Vehicle.h"

namespace ODemo {
/**
 * A LandVehicle drives on land.
 */
class LandVehicle : public Vehicle
{
public:
	/// default constructor.
	LandVehicle();

	/// Copy constructor.
	LandVehicle(const LandVehicle& ori);

	/// Move constructor.
	LandVehicle(LandVehicle&& ori);

	/// Copy assignment.
	LandVehicle& operator=(const LandVehicle& rhs);

	/// Move assignment.
	LandVehicle& operator=(LandVehicle&& rhs);

	/// Destructor.
	virtual ~LandVehicle();

	/// Pure virtual function: motion for the LandVehicle.
	virtual void move(double speed, std::vector<double> direction) = 0;

	/// Displa identification info.
	virtual void get_info() const;
};
}

#endif // end-of-include-guard
