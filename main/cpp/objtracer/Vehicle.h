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

        /// Motion of vehicle.
        virtual void move(double speed, std::vector<double> direction) = 0;

        /// Return vehicle information.
        virtual std::string get_info() const = 0;
};
}
