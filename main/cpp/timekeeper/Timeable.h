#pragma once
/*
 *  This file is part of the gobelijn software.
 *  Gobelijn is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or any later
 *  version. Gobelijn is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for details. You should have received
 *  a copy of the GNU General Public License along with the software. If not,
 *  see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2012, Jan Broeckhove.
 */
/**
 * @file
 * Utility class to record durations.
 */

#include "ClockCLib.h"
#include "Stopwatch.h"
#include <chrono>

namespace UA_CoMP {
namespace Timekeeper {

/**
 * Records durations associated with a name.
 * Template parameter is duration type (default std::chrono::seconds).
 */
template <typename C = ClockCLib, typename D = C::duration>
class Timeable
{
public:
        /// Type for time duration units.
        using Duration = D;

        /// Records with timing info.
        using Timings = UA_CoMP::Timekeeper::CumulativeRecords<D>;

        /// Type for clock.
        using Clock = C;

        /// Clock used to obtain timing info.
        using Stopwatch = UA_CoMP::Clock::Stopwatch<C>;

public:
        /// Destructor virtual for polymorphic class.
        virtual ~Timeable() {}

        /// Timings in duration units specified above.
        virtual TimingsType GetTimings() const = 0;
};

} // namespace
} // namespace

