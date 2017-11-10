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
 *  Copyright 2016, Jan Broeckhove.
 */
/**
 * @file.
 * Employee POD.
 */

#include <string>

namespace AbstractFactory {
/**
 * A data structure that represents an employee's data. Instances of this
 * type can be constructed by a factory.
 */
struct Employee
{
        std::string Name;               ///< Stores the person's name.
        std::string DepartmentName;     ///< Stores the name of the employee's department.
        double Salary;                  ///< Stores the employee's monthly wage.
};
}
