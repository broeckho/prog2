#pragma once
/**
 * @file
 * Header for the WaterVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/Vehicle.h"

namespace ODemo {

/**
 * Abstract WaterVehicle class.
 */
class WaterVehicle : public Vehicle
{
public:
	/// Default constructor.
	WaterVehicle();

	/// Copy constructor.
	WaterVehicle(const WaterVehicle& ori);

	/// Move constructor.
	WaterVehicle(WaterVehicle&& ori) noexcept;

	/// Copy assignment.
	WaterVehicle& operator=(const WaterVehicle& rhs);

	/// Move assignment.
	WaterVehicle& operator=(WaterVehicle&& rhs) noexcept;

	/// Destructor.
	~WaterVehicle() override;

	/// Pure virtual method for motion.
	void move(double speed, std::vector<double> direction) override = 0;

	/// Start sinking, even if you are already sinking.
	void start_sinking();

	/// Stop sinking, even if you were not sinking in the first place.
	void stop_sinking();

	/// Display identification info.
	void get_info() const override;

private:
	bool m_sinking;
};

} // end_of_namespace

