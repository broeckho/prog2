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
 * Main for Abstract Factory demo.
 */

// This program illustrates the abstract factory pattern.
// The abstract factory class template in 'factory.h' has three implementations:
//
//     * ConstantFactory, which always returns the same pre-defined value.
//       ('constant-factory.h')
//
//     * StdinEmployeeFactory, which uses standard output to ask the user
//       specific questions, and constructs a new Employee instance based on
//       the user's answers, which are read from standard input.
//       ('stdin-employee-factory.h', 'stdin-employee-factory.cpp')
//
//     * PtreeEmployeeFactory, which extracts data from Boost property trees,
//       and uses that to build Employee instances. ('ptree-employee-factory.h',
//       'ptree-employee-factory.cpp')
//
// These implementations are used in this program to construct employees,
// and print their data.

#include "constant-factory.h"
#include "employee.h"
#include "ptree-employee-factory.h"
#include "stdin-employee-factory.h"

#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

using namespace AbstractFactory;

/**
 * Writes to standard output all information that pertains to the given
 * employee.
 */
void printEmployee(const Employee& employee)
{
        std::cout << "name: " << employee.Name << std::endl
                  << "department: " << employee.DepartmentName << std::endl
                  << "salary: " << employee.Salary << std::endl;
}

/**
 * Instructs the given factory to create an Employee instance, and then writes
 * all information pertaining to that instance to standard output.
 */
void printEmployee(Factory<Employee>& factory) { printEmployee(factory.Create()); }

/**
 * Creates a Boost property tree that represents the given employee instance.
 */
boost::property_tree::ptree toPtree(const Employee& employee)
{
        boost::property_tree::ptree result;
        result.put(PtreeEmployeeFactory::EmployeeNameKey, employee.Name);
        result.put(PtreeEmployeeFactory::EmployeeDepartmentNameKey, employee.DepartmentName);
        result.put(PtreeEmployeeFactory::EmployeeSalaryKey, employee.Salary);
        return result;
}

int main()
{
        // Create a constant employee.
        std::cout << "Predefined employee:" << std::endl;

        Employee constEmployee;
        constEmployee.Name = "John Doe";
        constEmployee.DepartmentName = "IT";
        constEmployee.Salary = 2500;

        ConstantFactory<Employee> constFactory(constEmployee);
        printEmployee(constFactory);

        // Create an employee from standard input.
        std::cout << "Build your own employee:" << std::endl;
        StdinEmployeeFactory stdinFactory;
        auto userEmployee = stdinFactory.Create();
        printEmployee(userEmployee);

        // Now, we'll read an employee from an XML file. To keep things simple,
        // we'll just serialize the employee the user just described, write it
        // to disk as XML, and then read that again.

        std::cout << "XML employee:" << std::endl;
        boost::property_tree::xml_parser::write_xml("tmp_config.xml", toPtree(userEmployee));
        boost::property_tree::ptree pt;
        boost::property_tree::xml_parser::read_xml("tmp_config.xml", pt);
        PtreeEmployeeFactory ptreeFactory(pt);
        printEmployee(ptreeFactory);
}
