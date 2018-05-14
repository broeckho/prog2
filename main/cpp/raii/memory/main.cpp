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
 * Main using the RAII Buffer class.
 */

#include "buffer.h"
#include <iostream>

using namespace Raii;

/**
 * Prints the contents of a buffer.
 */
void printBuffer(const Buffer& buf)
{
        std::cout << "size: " << buf.GetSize() << ", data: ";
        for (unsigned int i = 0; i < buf.GetSize(); i++) {
                if (i > 0)
                        std::cout << ", ";

                // Convert the buffer's items to integers before printing them.
                // Otherwise, they will be printed as their ASCII values (which are
                // probably gibberish)
                std::cout << static_cast<int>(buf[i]);
        }
        std::cout << std::endl;
}

int main()
{
        // 'buf1' is allocated and initialized
        Buffer buf1(4);
        buf1[1] = 2;
        printBuffer(buf1);
        {
                // Copy-construct 'buf2' from 'buf1'; a new memory block is created for
                // 'buf2', which has the same contents as 'buf1's memory block.
                Buffer buf2 = buf1;
                buf2[3] = 16;
                printBuffer(buf1);
                printBuffer(buf2);
                // Move-assign 'buf2' to 'buf1'. 'buf1's memory block is now
                // deallocated, and replaced by 'buf2's memory block.
                buf1 = std::move(buf2);
                // 'buf2's memory block is not deallocated here, because it has been
                // moved to 'buf1'.
        }
        printBuffer(buf1);
        // 'buf2's memory block is deallocated.
}
