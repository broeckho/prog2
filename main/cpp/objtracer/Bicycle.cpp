/**
 * @file
 * Implementation for the class Bicycle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "Bicycle.h"
#include "tracer/tracer.h"

namespace ODemo {

using namespace std;

Bicycle::Bicycle() : PassengerRoadVehicle(2), m_model("Unknown model"), m_color("Unknown color")
{
        COMP_MISC_MEMBER_TRACER;
}

Bicycle::Bicycle(std::string model, std::string color)
    : PassengerRoadVehicle(2), m_model(std::move(model)), m_color(std::move(color))
{
        COMP_MISC_MEMBER_TRACER;
}

Bicycle::Bicycle(const Bicycle& ori) : PassengerRoadVehicle(ori), m_model(ori.m_model), m_color(ori.m_color)
{
        COMP_MISC_MEMBER_TRACER;
}

Bicycle::Bicycle(Bicycle&& ori) noexcept
    : PassengerRoadVehicle(std::move(ori)), m_model(std::move(ori.m_model)), m_color(std::move(ori.m_color))
{
        COMP_MISC_MEMBER_TRACER;
}

Bicycle& Bicycle::operator=(const Bicycle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                PassengerRoadVehicle::operator=(rhs);
                this->m_model = rhs.m_model;
                this->m_color = rhs.m_color;
        }
        return *this;
}

Bicycle& Bicycle::operator=(Bicycle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                PassengerRoadVehicle::operator=(rhs);
                m_model = std::move(rhs.m_model);
                m_color = std::move(rhs.m_color);

                // Leave the argument in an indeterminate state.
                rhs.m_model = nullptr;
                rhs.m_color = nullptr;
        }
        return *this;
}

Bicycle::~Bicycle()
{
        COMP_MISC_MEMBER_TRACER;
}

string Bicycle::getModel() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_model;
}

string Bicycle::getColor() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_color;
}

void Bicycle::setModel(string model)
{
        COMP_MISC_MEMBER_TRACER;
        m_model = std::move(model);
}

void Bicycle::setColor(string color)
{
        COMP_MISC_MEMBER_TRACER;
        m_color = std::move(color);
}

void Bicycle::info() const
{
        COMP_MISC_MEMBER_TRACER;
        const string s = {"I'm a bicycle: model = " + m_model + ", color = " + m_color};
        COMP_MISC_LOG_TRACER(s);
}

} // end of namespace
