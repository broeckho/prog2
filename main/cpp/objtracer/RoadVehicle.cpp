/**
 * @file
 * Implementation for the class RoadVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/RoadVehicle.h"
#include "tracer/tracer.h"

namespace ODemo {

using namespace std;

RoadVehicle::RoadVehicle() : LandVehicle() { COMP_MISC_MEMBER_TRACER; }

RoadVehicle::RoadVehicle(const RoadVehicle& ori) : LandVehicle(ori) { COMP_MISC_MEMBER_TRACER; }

RoadVehicle::RoadVehicle(RoadVehicle&& ori) noexcept : LandVehicle(std::move(ori)) { COMP_MISC_MEMBER_TRACER; }

RoadVehicle& RoadVehicle::operator=(const RoadVehicle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                LandVehicle::operator=(rhs);
        }
        return *this;
}

RoadVehicle& RoadVehicle::operator=(RoadVehicle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                LandVehicle::operator=(rhs);
        }
        return *this;
}

RoadVehicle::~RoadVehicle() { COMP_MISC_MEMBER_TRACER; }

void RoadVehicle::info() const
{
        COMP_MISC_MEMBER_TRACER;
        const string s{"I'm a generic Road vehicle"};
        COMP_MISC_LOG_TRACER(s);
}

void RoadVehicle::move(double, vector<double>) { COMP_MISC_MEMBER_TRACER; }

} // namespace ODemo
