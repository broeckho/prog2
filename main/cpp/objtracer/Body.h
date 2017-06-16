#ifndef INC_GOBELIJN_OBJTRACER_BODY_H
#define INC_GOBELIJN_OBJTRACER_BODY_H
/**
 * @file
 * Header for Bicycle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/PassengerRoadVehicle.h"
#include <string>
#include <utility>

namespace ODemo {

class Body
{
public:
	/// Constructor.
	Body(std::string color = "blue");

	/// Copy constructor
	Body(Body const& ori);

	/// Move constructor
	Body(Body&& ori);

	/// Copy assingment
	Body& operator=(Body const& rhs);

	/// Move assingment
	Body& operator=(Body&& rhs);

private:
	std::string m_color;
};
}

#endif // end-of-include-guard
