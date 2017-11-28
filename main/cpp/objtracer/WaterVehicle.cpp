/**
 * @file
 * Implementation for the class WaterVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/WaterVehicle.h"
#include "tracer/tracer.h"

namespace ODemo {

using namespace std;

WaterVehicle::WaterVehicle() : Vehicle(), m_sinking(false)
{
        COMP_MISC_MEMBER_TRACER;
}

WaterVehicle::WaterVehicle(const WaterVehicle& ori) : Vehicle(ori), m_sinking(ori.m_sinking)
{
        COMP_MISC_MEMBER_TRACER;
}

WaterVehicle::WaterVehicle(WaterVehicle&& ori) noexcept : Vehicle(ori), m_sinking(ori.m_sinking)
{
        COMP_MISC_MEMBER_TRACER;
}

WaterVehicle& WaterVehicle::operator=(const WaterVehicle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                Vehicle::operator=(rhs);
                m_sinking = rhs.m_sinking;
        }
        return *this;
}

WaterVehicle& WaterVehicle::operator=(WaterVehicle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                Vehicle::operator=(rhs);
                m_sinking = rhs.m_sinking;
        }
        return *this;
}

WaterVehicle::~WaterVehicle()
{
        COMP_MISC_MEMBER_TRACER;
}

void WaterVehicle::info() const
{
        COMP_MISC_MEMBER_TRACER;
        string s {"I'm a generic Water vehicle"};
        if (m_sinking) {
                s.append(" and I'm sinking!");
        }
        COMP_MISC_LOG_TRACER(s);
}

void WaterVehicle::start_sinking()
{
        COMP_MISC_MEMBER_TRACER;
        m_sinking = true;
}

void WaterVehicle::stop_sinking()
{
        COMP_MISC_MEMBER_TRACER;
        m_sinking = false;
}

} // end of namespace
