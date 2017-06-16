/**
 * @file
 * Implementation for the class Bicycle.
 * @author P. Klosiewicz, J.Broeckhove  CoMP/UA
 */

#include "Bicycle.h"
#include "tracer/tracer.h"
#include <iostream>

namespace ODemo {

using namespace std;

/**
 * @return		None.
 */
Bicycle::Bicycle() : PassengerRoadVehicle(2), m_model("Unknown model"), m_color("Unknown color")
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @return                  None.
 * @param       model       Initializes model of motorcycle.
 * @param       color       Initializes color of motorcycle.
 */
Bicycle::Bicycle(std::string model, std::string color) : PassengerRoadVehicle(2), m_model(model), m_color(color)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @return			None.
 * @param		ori	Original to be copied.
 */
Bicycle::Bicycle(const Bicycle& ori) : PassengerRoadVehicle(ori), m_model(ori.m_model), m_color(ori.m_color)
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * @return			None.
 * @param		ori	Original to be moved.
 */
Bicycle::Bicycle(Bicycle&& ori)
    : PassengerRoadVehicle(std::move(ori)), m_model(std::move(ori.m_model)), m_color(std::move(ori.m_color))
{
	COMP_MISC_MEMBER_TRACER;
}

/**
 * Copy assignment include guard against self-assignment.
 * @return                      None.
 * @param               rhs     Right hand side in assignment.
 */
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

/**
 * Move assignment include guard against self-assignment.
 * @return                      None.
 * @param               rhs     Right hand side in assignment.
 */
Bicycle& Bicycle::operator=(Bicycle&& rhs)
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

/**
 * Destructor has to be virtual, because we are in a inheritance hierarchy.
 * @return                      None.
 */
Bicycle::~Bicycle() { COMP_MISC_MEMBER_TRACER; }

/**
 * @return      string  Model.
 */
string Bicycle::getModel() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_model;
}

/**
 * @return      string  Color.
 */
string Bicycle::getColor() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_color;
}

/**
 * @return              None.
 * @param       model   Value that model is set to.
 */
void Bicycle::setModel(string model)
{
	COMP_MISC_MEMBER_TRACER;
	m_model = model;
}

/**
 * @return              None.
 * @param       color   Value that color is set to.
 */
void Bicycle::setColor(string color)
{
	COMP_MISC_MEMBER_TRACER;
	m_color = color;
}

/**
 * @return              None.
 */
void Bicycle::get_info() const
{
	COMP_MISC_MEMBER_TRACER;
	cout << "I'm a bicycle: model = " << m_model << ", color = " << m_color << endl;
	PassengerRoadVehicle::get_info();
}
}
