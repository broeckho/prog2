#pragma once
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
	explicit SailBoat(std::string name);

	/// Copy constructor.
	SailBoat(const SailBoat& ori);

	/// Move constructor.
	SailBoat(SailBoat&& ori)  noexcept ;

	/// Copy assignment.
	SailBoat& operator=(const SailBoat& rhs);

	/// Move assignment.
	SailBoat& operator=(SailBoat&& rhs) noexcept;

	/// Destructor.
	~SailBoat() override ;

	/// Sailboat motion.
	void move(double speed, std::vector<double> direction) override;

	/// Display identification info.
	void get_info() const override;

private:
	std::string m_name;
	bool m_sails_up;
};

} // end_of_namespace

