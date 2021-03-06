/**
 * @file
 * Implementation for the class LandVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/LandVehicle.h"
#include "tracer/tracer.h"

namespace ODemo {

using namespace std;

LandVehicle::LandVehicle() : Vehicle() { COMP_MISC_MEMBER_TRACER; }

LandVehicle::LandVehicle(const LandVehicle& ori) : Vehicle(ori) { COMP_MISC_MEMBER_TRACER; }

LandVehicle::LandVehicle(LandVehicle&& ori) noexcept : Vehicle(ori) { COMP_MISC_MEMBER_TRACER; }

LandVehicle& LandVehicle::operator=(const LandVehicle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                Vehicle::operator=(rhs);
        }
        return *this;
}

LandVehicle& LandVehicle::operator=(LandVehicle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                Vehicle::operator=(rhs);
        }
        return *this;
}

LandVehicle::~LandVehicle() { COMP_MISC_MEMBER_TRACER; }

void LandVehicle::info() const
{
        COMP_MISC_MEMBER_TRACER;
        const string s{"I'm a generic Land vehicle"};
        COMP_MISC_LOG_TRACER(s);
}

} // namespace ODemo
