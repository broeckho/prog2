#ifndef INC_GOBELIJN_OBJTRACER_SAILBOAT_H
#define INC_GOBELIJN_OBJTRACER_SAILBOAT_H
/**
 * @file
 * Header for the SailBoat class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/WaterVehicle.h"
#include <string>

namespace ODemo {
/**
 * A simple SailBoat class.
 */
class SailBoat : public WaterVehicle
{
public:
	/// Parametrized constructor initializes the name of the boat.
	SailBoat(std::string name);

	/// Copy constructor.
	SailBoat(const SailBoat& ori);

	/// Move constructor.
	SailBoat(SailBoat&& ori);

	/// Copy assignment.
	SailBoat& operator=(const SailBoat& rhs);

	/// Move assignment.
	SailBoat& operator=(SailBoat&& rhs);

	/// Destructor.
	virtual ~SailBoat();

	/// Sailboat motion.
	virtual void move(double speed, std::vector<double> direction);

	/// Display identification info.
	virtual void get_info() const;

private:
	std::string m_name;
	bool m_sails_up;
};
}

#endif // end-of-include-guard
