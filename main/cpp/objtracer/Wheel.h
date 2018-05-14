#pragma once
/**
 * @file
 * Header for the Wheel class used to demo object aggregation features.
 * @author J.Broeckhove  CoMP/UA
 */

namespace ODemo {

/**
 * A really simple class for Wheel.
 */
class Wheel
{
public:
        /// Default constructor.
        Wheel();

        /// Copy constructor.
        Wheel(const Wheel& ori);

        /// Move constructor.
        Wheel(Wheel&& ori) noexcept;

        /// Copy assignment operator.
        Wheel& operator=(const Wheel& rhs);

        /// Move assignment operator.
        Wheel& operator=(Wheel&& rhs) noexcept;

        /// destructor.
        ~Wheel();

        /// Start turning.
        void start();

        /// Stop turning.
        void stop();

        /// Indicate whether wheel is rotating or not.
        bool is_rotating() const;

private:
        double m_speed;
        bool m_rotating;
};

} // namespace ODemo
