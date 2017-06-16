#ifndef INC_GOBELIJN_OBJTRACER_WHEEL_H
#define INC_GOBELIJN_OBJTRACER_WHEEL_H
/**
 * @file
 * Header for the Wheel class used to demo object aggregation features.
 * @author J.Broeckhove  CoMP/UA
 */

namespace ODemo {

/**
 * A really simple class for Wheel.
 */
class Wheel
{
public:
	/// Default constructor.
	Wheel(double size = 1.0e0);

	/// Copy constructor.
	Wheel(const Wheel& ori);

	/// Move constructor.
	Wheel(Wheel&& ori);

	/// Copy assignment operator.
	Wheel& operator=(const Wheel& rhs);

	/// Move assignment operator.
	Wheel& operator=(Wheel&& rhs);

	/// destructor.
	~Wheel();

	/// Start turning.
	void start();

	/// Stop turning.
	void stop();

	/// Indicate whether wheel is rotating or not.
	bool is_rotating() const;

private:
	double m_speed;
	bool m_rotating;
};

} // namespace ODemo

#endif // end-of-include-guard
