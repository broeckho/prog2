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
 *  Copyright 2012, Jan Broeckhove, CoMP research group, Universiteit Antwerpen.
 */
/**
 * @file
 * Main program for gtest runs.
 */

#include "util/Exception.h"
#include <cerrno>
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using UA_CoMP::Util::Exception;

int main(int argc, char** argv)
{
        int exit_status = EXIT_SUCCESS;
        try {
                ::testing::InitGoogleTest(&argc, argv);
                return RUN_ALL_TESTS();
        } catch (Exception& e) {
                cerr << "Exception caught: " << e.what() << endl << ">>>>> Aborting VirtualLeaf2" << endl;
                exit_status = EXIT_FAILURE;
        }
        return exit_status;
}
