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
 * Concrete ptree based factory.
 */

#include "employee.h"
#include "factory.h"
#include <boost/property_tree/ptree.hpp>

namespace AbstractFactory {
/**
 * An employee factory implementation that uses Boost property trees to
 * construct employee instances.
 */
class PtreeEmployeeFactory : public Factory<Employee>
{
public:
        /// Creates a factory that analyzes the given property tree, and construct an employee instance.
        explicit PtreeEmployeeFactory(const boost::property_tree::ptree& ptree) : m_ptree(ptree) {}

        /// Instructs this factory to create a value.
        Employee Create() final;

        /// The Boost property tree key for the employees' names.
        static constexpr const char* EmployeeNameKey = "Name";

        /// The Boost property tree key for the employees' department names.
        static constexpr const char* EmployeeDepartmentNameKey = "DepartmentName";

        /// The Boost property tree key for the employees' salaries.
        static constexpr const char* EmployeeSalaryKey = "Salary";

private:
        boost::property_tree::ptree m_ptree;
};
} // namespace AbstractFactory
