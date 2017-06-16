#ifndef INC_GOBELIJN_OBJTRACER_WATERVEHICLE_H
#define INC_GOBELIJN_OBJTRACER_WATERVEHICLE_H
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
	WaterVehicle(WaterVehicle&& ori);

	/// Copy assignment.
	WaterVehicle& operator=(const WaterVehicle& rhs);

	/// Move assignment.
	WaterVehicle& operator=(WaterVehicle&& rhs);

	/// Destructor.
	virtual ~WaterVehicle();

	/// Pure virtual method for motion.
	virtual void move(double speed, std::vector<double> direction) = 0;

	/// Start sinking, even if you are already sinking.
	void start_sinking();

	/// Stop sinking, even if you were not sinking in the first place.
	void stop_sinking();

	/// Display identification info.
	virtual void get_info() const;

private:
	bool m_sinking;
};

} // namespace ODemo

#endif // end-of-include-guard
