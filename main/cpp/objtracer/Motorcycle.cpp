/**
 * @file
 * Implementation of Motorcycle used to demo object aggregation features.
 * @author J.Broeckhove  CoMP/UA
 */

#include "objtracer/Motorcycle.h"
#include "tracer/tracer.h"
#include "util/Exception.h"

#include <memory>

namespace ODemo {

using namespace std;
using UA_CoMP::Util::Exception;

Motorcycle::Motorcycle()
    : m_engine(new Engine(10.0)), m_body(new Body()), m_owner(nullptr), m_wheels(std::array<Wheel, 2>()), m_speed(0.0),
    m_direction(0.0)
{
        COMP_MISC_MEMBER_TRACER;
        m_wheels[0] = Wheel();
        m_wheels[1] = Wheel();
}

Motorcycle::Motorcycle(const shared_ptr<Engine>& enginePtr)
    : m_engine(enginePtr), m_body(new Body()), m_owner(nullptr), m_wheels(std::array<Wheel, 2>()), m_speed(0.0),
    m_direction(0.0)
{
        COMP_MISC_MEMBER_TRACER;
}

Motorcycle::Motorcycle(const shared_ptr<Engine>& enginePtr, const Person* ownerPtr)
    : m_engine(enginePtr), m_body(new Body()), m_owner(ownerPtr), m_wheels(std::array<Wheel, 2>()), m_speed(0.0),
    m_direction(0.0)
{
        COMP_MISC_MEMBER_TRACER;
}

Motorcycle::Motorcycle(const Motorcycle& ori)
    : m_engine(nullptr), m_body(new Body(*ori.m_body)), m_owner(ori.m_owner), m_wheels(ori.m_wheels),
    m_speed(ori.m_speed), m_direction(ori.m_direction)
{
        COMP_MISC_MEMBER_TRACER;
        if (ori.m_engine) {
                m_engine = make_shared<Engine>(*ori.m_engine);
        }
}

Motorcycle::Motorcycle(Motorcycle&& ori) noexcept
    : m_engine(std::move(ori.m_engine)), m_body(std::move(ori.m_body)), m_owner(ori.m_owner),
      m_wheels(std::move(ori.m_wheels)), m_speed(ori.m_speed), m_direction(ori.m_direction)
{
        COMP_MISC_MEMBER_TRACER;
        ori.m_engine = nullptr;
        ori.m_body = nullptr;
        ori.m_wheels = array<Wheel, 2>();
        ori.m_owner = nullptr;
        ori.m_speed = 0.0;
        ori.m_direction = 0.0;
}

Motorcycle& Motorcycle::operator=(const Motorcycle& rhs)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                if (rhs.m_engine == nullptr) {
                        m_engine = nullptr;
                } else {
                        m_engine = make_shared<Engine>(*rhs.m_engine);
                }
                m_body = make_unique<Body>(*rhs.m_body);
                m_wheels = rhs.m_wheels;
                m_owner = rhs.m_owner;
                m_speed = rhs.m_speed;
                m_direction = rhs.m_direction;
        }
        return *this;
}

Motorcycle& Motorcycle::operator=(Motorcycle&& rhs) noexcept
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &rhs) {
                m_engine = std::move(rhs.m_engine);
                m_body = std::move(rhs.m_body);
                m_wheels = std::move(rhs.m_wheels);
                m_owner = rhs.m_owner;
                m_speed = rhs.m_speed;
                m_direction = rhs.m_direction;

                rhs.m_engine = nullptr;
                rhs.m_body = nullptr;
                rhs.m_wheels = array<Wheel, 2>();
                rhs.m_owner = nullptr;
                rhs.m_speed = 0.0;
                rhs.m_direction = 0.0;
        }
        return *this;
}

Motorcycle::~Motorcycle() { COMP_MISC_MEMBER_TRACER; }

void Motorcycle::startEngine()
{
        COMP_MISC_MEMBER_TRACER;
        if (m_engine == nullptr) {
                throw Exception("Motorcycle::startEngine> Motorcycle without engine cannot start !");
        }
        if (!m_engine->is_running()) {
                m_engine->start();
                m_speed = 0.0;
        }
}

void Motorcycle::stopEngine()
{
        COMP_MISC_MEMBER_TRACER;
        if (m_engine == nullptr) {
                throw Exception("Motorcycle without engine cannot stop !");
        }
        if (m_engine->is_running()) {
                if (m_speed > 0.0) {
                        halt();
                }
                m_engine->stop();
        }
}

void Motorcycle::accelerate(double speed)
{
        COMP_MISC_MEMBER_TRACER;
        if (m_engine == nullptr) {
                throw Exception("Motorcycle without engine cannot accelerate !");
        }
        if (m_engine->is_running() & (m_speed < speed)) {
                m_speed = speed;
        }
}

void Motorcycle::brake(double speed)
{
        COMP_MISC_MEMBER_TRACER;
        if (m_engine == nullptr) {
                throw Exception("Motorcycle without engine cannot brake !");
        }
        if (m_engine->is_running() & (m_speed > speed)) {
                m_speed = speed;
        }
}

void Motorcycle::halt()
{
        COMP_MISC_MEMBER_TRACER;
        brake(0.0);
}

void Motorcycle::turn(double degrees)
{
        COMP_MISC_MEMBER_TRACER;
        if (m_speed > 0.0) {
                m_direction += degrees;
        }
}

double Motorcycle::getSpeed() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_speed;
}

bool Motorcycle::is_running() const
{
        COMP_MISC_MEMBER_TRACER;
        if (m_engine == nullptr) {
                throw Exception("Motorcycle without engine cannot run !");
        }
        return m_engine->is_running();
}

shared_ptr<Engine> Motorcycle::get_engine()
{
        COMP_MISC_MEMBER_TRACER;
        return m_engine;
}

const Person* Motorcycle::get_owner() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_owner;
}

void Motorcycle::set_engine(shared_ptr<Engine> const& newEnginePtr)
{
        COMP_MISC_MEMBER_TRACER;
        m_engine = newEnginePtr;
}

void Motorcycle::set_owner(Person* newOwnerPtr)
{
        COMP_MISC_MEMBER_TRACER;
        m_owner = newOwnerPtr;
}

} // namespace ODemo
