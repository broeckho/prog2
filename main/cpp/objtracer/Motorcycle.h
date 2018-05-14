#pragma once
/**
 * @file
 * Header for the Motorcycle class.
 * @author J.Broeckhove  CoMP/UA
 */

#include "objtracer/Body.h"
#include "objtracer/Engine.h"
#include "objtracer/Person.h"
#include "objtracer/Wheel.h"
#include <array>
#include <memory>

namespace ODemo {

/**
 * Motorcycle with Engine and Owner.
 */
class Motorcycle
{
public:
        /// Default constructor does not initialize association with engine and owner.
        Motorcycle();

        /// Constructor initializes association with engine only.
        explicit Motorcycle(std::shared_ptr<Engine> const& enginePtr);

        /// Constructor initializes association with engine and owner.
        Motorcycle(std::shared_ptr<Engine> const& enginePtr, Person const* ownerPtr);

        /// Copy constructor.
        Motorcycle(Motorcycle const& ori);

        /// Move constructor.
        Motorcycle(Motorcycle&& ori) noexcept;

        /// Copy assignment
        Motorcycle& operator=(Motorcycle const& rhs);

        /// Move assignment
        Motorcycle& operator=(Motorcycle&& rhs) noexcept;

        /// Destructor.
        ~Motorcycle();

        /// Start the motorcycle engine.
        void startEngine();

        /// Stop the motorcycle engine.
        void stopEngine();

        /// Accelerate up to given speed.
        void accelerate(double speed);

        /// Brake until given speed.
        void brake(double speed);

        /// Brake to zero speed, keep engine running.
        void halt();

        // Turn with given number of degrees.
        void turn(double degrees);

        /// Return current speed.
        double getSpeed() const;

        /// Indicates whether engine is running or not.
        bool is_running() const;

        /// Returns pointer to the Engine (may be 0).
        std::shared_ptr<Engine> get_engine();

        /// Returns pointer to the owner (may be 0).
        Person const* get_owner() const;

        /// Resets engine.
        void set_engine(std::shared_ptr<Engine> const& newEnginePtr);

        /// Resets owner.
        void set_owner(Person* newOwnerPtr);

private:
        std::shared_ptr<Engine> m_engine;
        std::unique_ptr<Body> m_body;
        const Person* m_owner;
        std::array<Wheel, 2> m_wheels;
        double m_speed;
        double m_direction;
};

} // namespace ODemo
