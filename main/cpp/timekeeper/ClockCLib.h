#pragma once

#include <chrono>
#include <ctime>
#include <stdexcept>

namespace UA_CoMP {
namespace Timekeeper {

/**
 * Clock based on C library clock_t clock() which returns an
 * approximate processor time in ticks. There are CLOCKS_PER_SEC
 * ticks per second and POSIX requires this be 1000000.
 */
class ClockCLib
{
public:
        typedef std::chrono::milliseconds duration;
        typedef duration::rep rep;
        typedef duration::period period;
        typedef std::chrono::time_point<ClockCLib, duration> time_point;

        static time_point now()
        {
                std::clock_t t = std::clock();
                if (static_cast<std::clock_t>(-1) == t) {
                        throw std::runtime_error("Error in CallClockCLib");
                }

                constexpr double conv = 1.0 / CLOCKS_PER_SEC;
                constexpr double ratio = static_cast<double>(period::den) / static_cast<double>(period::num);
                const duration d(static_cast<rep>(static_cast<double>(t) * conv * ratio));
                return time_point(d);
        }
};

} // end-of-namespace
} // end-of-namespace

