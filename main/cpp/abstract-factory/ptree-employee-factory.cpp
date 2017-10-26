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
 * Concrete ptree based factory.
 */

#include "ptree-employee-factory.h"

namespace AbstractFactory {
/**
 * Instructs this factory to create a value.
 */
Employee PtreeEmployeeFactory::Create()
{
        // Grab some values from the ptree, and use them to build an Employee
        // instance.
        Employee result;
        result.Name = m_ptree.get_child(EmployeeNameKey).get_value<std::string>();
        result.DepartmentName = m_ptree.get_child(EmployeeDepartmentNameKey).get_value<std::string>();
        result.Salary = m_ptree.get_child(EmployeeSalaryKey).get_value<double>();
        return result;
}
}
