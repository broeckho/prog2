#ifndef INC_GOBELIJN_OBJTRACER_ROADVEHICLE_H
#define INC_GOBELIJN_OBJTRACER_ROADVEHICLE_H
/**
 * @file
 * Header for the RoadVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/LandVehicle.h"
#include <vector>

namespace ODemo {

/**
 * A RoadVehicle is any kind of vehicle that moves on the road.
 */
class RoadVehicle : public LandVehicle
{
public:
	/// Default constructor.
	RoadVehicle();

	/// Copy constructor.
	RoadVehicle(const RoadVehicle& ori);

	/// Move constructor.
	RoadVehicle(RoadVehicle&& ori);

	/// Copy assignment operator.
	RoadVehicle& operator=(const RoadVehicle& rhs);

	/// Move assignment operator.
	RoadVehicle& operator=(RoadVehicle&& rhs);

	/// Destructor.
	virtual ~RoadVehicle();

	/// Motion of the vehicle.
	virtual void move(double speed, std::vector<double> direction);

	/// Display identification info.
	virtual void get_info() const;
};
}

#endif // end-of-include-guard
