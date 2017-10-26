#pragma once
/**
 * @file
 * Header for the Vehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include <vector>

namespace ODemo {

/**
 * This Vehicle interface class.
 */
class Vehicle
{
public:
        /// Destructor.
        virtual ~Vehicle() = default;

        /// Motion of vehicle.
        virtual void move(double speed, std::vector<double> direction) = 0;

        /// Display of vehicle information.
        virtual void get_info() const = 0;
};
}
