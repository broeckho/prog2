/**
 * @file
 * Implementation for the Engine class used to demo object aggregation features.
 * @author J. Broeckhove  CoMP/UA
 */

#include "objtracer/Engine.h"
#include "tracer/tracer.h"
#include <utility>

namespace ODemo {

///
Engine::Engine(double power) : m_power(power), m_running(false) { COMP_MISC_MEMBER_TRACER; }

///
Engine::Engine(Engine const& ori) : m_power(ori.m_power), m_running(ori.m_running) { COMP_MISC_MEMBER_TRACER; }

///
Engine::Engine(Engine&& ori) : m_power(std::move(ori.m_power)), m_running(std::move(ori.m_running))
{
	COMP_MISC_MEMBER_TRACER;
}

///
Engine& Engine::operator=(const Engine& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_power = rhs.m_power;
		m_running = rhs.m_running;
	}
	return *this;
}

///
Engine& Engine::operator=(Engine&& rhs)
{
	COMP_MISC_MEMBER_TRACER;
	if (this != &rhs) {
		m_power = std::move(rhs.m_power);
		m_running = std::move(rhs.m_running);

		// Leave the argument in an indeterminate state.
		rhs.m_power = 0.0;
		rhs.m_running = false;
	}
	return *this;
}

///
Engine::~Engine() { COMP_MISC_MEMBER_TRACER; }

///
void Engine::start()
{
	COMP_MISC_MEMBER_TRACER;
	if (!m_running) {
		m_running = true;
	}
}

///
void Engine::stop()
{
	COMP_MISC_MEMBER_TRACER;
	if (m_running) {
		m_running = false;
	}
}

///
bool Engine::is_running() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_running;
}

///
double Engine::get_power() const
{
	COMP_MISC_MEMBER_TRACER;
	return m_power;
}

} // end_of_namespace
