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
 *  Copyright 2016, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Varyadic template adder.
 */

#include <iostream>
#include <string>

using namespace std;

// Ends recursion of the varyadic template.
template <typename T>
T Adder(T v)
{
	cout << "\n\t ----> \n\t " << __PRETTY_FUNCTION__ << "\n\t <----- \n" << endl;

	return v;
}

// Varyadic template.
template <typename T, typename... Args>
T Adder(T first, Args... args)
{
	cout << "\n\t ----> \n\t " << __PRETTY_FUNCTION__ << "\n\t <----- \n" << endl;

	return first + Adder(args...);
}

// Demo.
int main()
{
	cout << Adder(1, 2, 3, 4) << endl;
	cout << Adder(2, 1.3, 1U, 2.0e2) << endl;
	cout << Adder(string("haha"), string("hihi"), string("hoho")) << endl;
}
