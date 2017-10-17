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
 *  Copyright 2016, Jan Broeckhove.
 */
/**
 * @file.
 * Concrete stdin input based factory.
 */

#include "stdin-employee-factory.h"

#include <iostream>

namespace AbstractFactory {
/**
 * Instructs this factory to create a value.
 */
Employee StdinEmployeeFactory::Create()
{
	// Use standard input to create the Employee instance.
	// Print some values to stdout to make sure the user knows
	// what is expected of them.
	Employee result;
	std::cout << "Hi, there. What's your name?" << std::endl;
	std::getline(std::cin, result.Name);
	std::cout << "Great! And what's your department?" << std::endl;
	std::getline(std::cin, result.DepartmentName);
	std::cout << "All right. One final question: what's your salary?" << std::endl;
	std::cin >> result.Salary;
	return result;
}
}
