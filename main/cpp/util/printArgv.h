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
 * @file.
 * Print (argc, argv) info.
 */
#include <iostream>

namespace UA_CoMP {
namespace Util {

void printArgv(int argc, char* argv[], std::ostream& os)
{
        os << "argc   : " << argc << std::endl;
        for (int i = 0; i < argc; i++) {
                os << "argv[" << i << "]: " << argv[i] << std::endl;
        }
        return;
}

} // namespace Util
} // namespace UA_CoMP
