/**
 * @file
 * Implementation for the class RoadVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/RoadVehicle.h"
#include "tracer/tracer.h"
#include <iostream>
#include <sstream>

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

void RoadVehicle::move(double speed, vector<double> direction)
{
        COMP_MISC_MEMBER_TRACER;
        cout << "RoadVehicle is moving with speed " << speed << " in direction" << endl;
        for (const auto& d : direction) {
                cout << d << endl;
        }
}

string RoadVehicle::get_info() const
{
        COMP_MISC_MEMBER_TRACER;
        stringstream ss;
        ss << "I'm a generic Road vehicle" << endl;
        ss << LandVehicle::get_info();
        return ss.str();
}
} // end of namespace
