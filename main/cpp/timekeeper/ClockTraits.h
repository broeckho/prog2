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
 * Types related to timekeeping.
 */

#include "ClockCLib.h"
#include "CumulativeRecords.h"
#include "Records.h"
#include "Stopwatch.h"
#include <chrono>

namespace UA_CoMP {
namespace Timekeeper {

/**
 * Types related to timekeeping.
 */
template <typename C = ClockCLib, typename D = typename C::duration>
class ClockTraits
{
public:
        /// Type for clock.
        using Clock = C;

        /// Stopwatch to measure time durations.
        using Stopwatch = UA_CoMP::Timekeeper::Stopwatch<C>;

        /// Type for time duration units.
        using Duration = D;

        /// Records with cumulative timing info.
        using CumulativeRecords = UA_CoMP::Timekeeper::CumulativeRecords<D>;

        /// Records with timing info.
        using Records = UA_CoMP::Timekeeper::Records<D>;
};

} // namespace Timekeeper
} // namespace UA_CoMP
