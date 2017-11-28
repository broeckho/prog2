/**
 * @file
 * Implementation for the class PassenggerRoadVehicle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "objtracer/PassengerRoadVehicle.h"
#include "tracer/tracer.h"
#include "util/StringUtils.h"
#include <iostream>
#include <sstream>

namespace ODemo {

using namespace std;
using namespace UA_CoMP::Util;

PassengerRoadVehicle::PassengerRoadVehicle(int numSeats)
        : RoadVehicle(), m_capacity(numSeats), m_free(numSeats)
{
        COMP_MISC_MEMBER_TRACER;
}

PassengerRoadVehicle::PassengerRoadVehicle(const PassengerRoadVehicle& ori)
    : RoadVehicle(ori), m_capacity(ori.m_capacity), m_free(ori.m_free)
{
        COMP_MISC_MEMBER_TRACER;
}

PassengerRoadVehicle::PassengerRoadVehicle(PassengerRoadVehicle&& ori) noexcept
    : RoadVehicle(std::move(ori)), m_capacity(ori.m_capacity), m_free(ori.m_free)
{
        COMP_MISC_MEMBER_TRACER;
}

PassengerRoadVehicle& PassengerRoadVehicle::operator=(const PassengerRoadVehicle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                RoadVehicle::operator=(rhs);
                m_capacity = rhs.m_capacity;
                m_free = rhs.m_free;
        }
        return *this;
}

PassengerRoadVehicle& PassengerRoadVehicle::operator=(PassengerRoadVehicle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                RoadVehicle::operator=(rhs);
                m_capacity = rhs.m_capacity;
                m_free = rhs.m_free;
        }
        return *this;
}

PassengerRoadVehicle::~PassengerRoadVehicle() { COMP_MISC_MEMBER_TRACER; }

bool PassengerRoadVehicle::add_passenger()
{
        COMP_MISC_MEMBER_TRACER;
        bool added = false;
        if (m_free > 0) {
                m_free--;
                added = true;
        }
        return added;
}

bool PassengerRoadVehicle::remove_passenger()
{
        COMP_MISC_MEMBER_TRACER;
        bool removed = false;
        if (m_free < m_capacity) {
                m_free++;
                removed = true;
        }
        return removed;
}

int PassengerRoadVehicle::get_capacity() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_capacity;
}

int PassengerRoadVehicle::get_free() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_free;
}

void PassengerRoadVehicle::info() const
{
        COMP_MISC_MEMBER_TRACER;
        const string s {"I'm a PassengerRoadVehicle: #seats = " + StringUtils::ToString(m_capacity)
                        + ", #free seats = " + StringUtils::ToString(m_free)};
        COMP_MISC_LOG_TRACER(s);
}

} // end of namespace
