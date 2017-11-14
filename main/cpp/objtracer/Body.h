#pragma once
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
        explicit Body(std::string color = "blue");

        /// Copy constructor
        Body(Body const& ori);

        /// Move constructor
        Body(Body&& ori) noexcept;

        /// Copy assingment
        Body& operator=(Body const& rhs);

        /// Move assingment
        Body& operator=(Body&& rhs) noexcept;

        /// Destructor
        ~Body();

        /// Weird operation
        Body operator+(const Body& b);

private:
        std::string m_color;
};

} // end_of_namespace
