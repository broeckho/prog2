#pragma once
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
	RoadVehicle(RoadVehicle&& ori) noexcept;

	/// Copy assignment operator.
	RoadVehicle& operator=(const RoadVehicle& rhs);

	/// Move assignment operator.
	RoadVehicle& operator=(RoadVehicle&& rhs) noexcept;

	/// Destructor.
	~RoadVehicle() override;

	/// Motion of the vehicle.
	void move(double speed, std::vector<double> direction) override;

	/// Display identification info.
	void get_info() const override;
};
}
