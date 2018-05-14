#pragma once
/**
 * @file
 * Header for the Vehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include <string>
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

        /// Return vehicle information.
        virtual void info() const = 0;

        /// Motion of vehicle.
        virtual void move(double speed, std::vector<double> direction) = 0;
};

} // namespace ODemo
