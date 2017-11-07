#ifndef GOBELIJN_STLDEMO_RANDINT_H
#define GOBELIJN_STLDEMO_RANDINT_H
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
 *  Copyright 2012, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Functor produces random values.
 */

// BEGIN_SNIPPET{FullSource}
#include <cstdlib>

/**
 * Produce random integer (int) values.
 */
class RandInt
{
public:
        /// Initialize seed and ranfe of generator.
        RandInt(unsigned int seed, unsigned long range) : m_seed(seed), m_range(range) { std::srand(m_seed); }
        /// return random int within  range.
        int operator()() { return rand() % m_range; }

private:
        int m_seed;
        unsigned long m_range;
};
// END_SNIPPET{FullSource}

#endif // end-of-include-guard
