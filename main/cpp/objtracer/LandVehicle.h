#pragma once
/**
 * @file
 * Header for the LandVehicle class.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/Vehicle.h"

namespace ODemo {
/**
 * A LandVehicle drives on land.
 */
class LandVehicle : public Vehicle
{
public:
        /// default constructor.
        LandVehicle();

        /// Copy constructor.
        LandVehicle(const LandVehicle& ori);

        /// Move constructor.
        LandVehicle(LandVehicle&& ori) noexcept;

        /// Copy assignment.
        LandVehicle& operator=(const LandVehicle& rhs);

        /// Move assignment.
        LandVehicle& operator=(LandVehicle&& rhs) noexcept;

        /// Destructor.
        ~LandVehicle() override;

        /// Pure virtual function: motion for the LandVehicle.
        void move(double speed, std::vector<double> direction) override = 0;

        /// Displa identification info.
        void get_info() const override;
};

} // end_of_namespace
