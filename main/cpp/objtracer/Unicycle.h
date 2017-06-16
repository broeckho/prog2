#ifndef INC_GOBELIJN_OBJTRACER_UNICYCLE_H
#define INC_GOBELIJN_OBJTRACER_UNICYCLE_H
/**
 * @file
 * Header for the Unicycle class.
 * @author J.Broeckhove  CoMP/UA
 */
#include "objtracer/Wheel.h"

namespace ODemo {

/**
 * Unicycle interface.
 */
class Unicycle
{
public:
	/// Default constructor does not initialize association with engine and owner.
	Unicycle(double wheel_size = 1.0e0);

	/// Copy constructor.
	Unicycle(const Unicycle& ori);

	/// Move constructor.
	Unicycle(Unicycle&& ori);

	/// Copy assignment
	Unicycle& operator=(const Unicycle& rhs);

	/// Copy assignment
	Unicycle& operator=(Unicycle&& rhs);

	/// Destructor.
	~Unicycle();

	/// Accelerate up to given speed.
	void accelerate(double speed);

	/// Brake until given speed.
	void brake(double speed);

	// Turn with given number of degrees.
	void turn(double degrees);

	/// Return current speed.
	double getSpeed() const;

	/// Indicates whether engine is running or not.
	bool is_running() const;

private:
	Wheel m_wheel;
	double m_speed;
	double m_direction;
};

} // end_of_namespace

#endif // end-of-include-guard
