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
 * Bin values in frequency table.
 */

// BEGIN_SNIPPET{FullSource}
#include "../stldemo_1/RandInt.h"
#include "../stldemo_1/Range.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename It>
std::map<typename It::value_type, unsigned int> freq(It first, It last)
{
	std::map<typename It::value_type, unsigned int> m;
	for (It it = first; it != last; ++it) {
		m[*it]++;
	}
	return m;
}

int main()
{
	std::vector<int> v(20);
	std::generate(v.begin(), v.end(), RandInt(2, 10));
	std::cout << make_range(v) << std::endl << make_range(freq(v.begin(), v.end())) << std::endl;
	return 0;
}
// END_SNIPPET{FullSource}
