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
 * Main using the RAII random read file class.
 */

#include <iostream>

#include "../files/file.h"
#include "random-read-file.h"

using namespace Raii;

// Reads out the given length-prefixed file in reverse.
void tacFile(const RandomReadFile& raFile)
{
        // First, read the file's length.
        auto length = static_cast<int>(raFile[0]);

        // Then, read out the file's data backwards.
        for (int i = length; i >= 1; i--)
                std::cout << raFile[i];
        std::cout << std::endl;
}

int main()
{
        // To test that random-read files actually work, we will encode the alphabet
        // in a file, prefix that by the alphabet's length, and then read it out
        // backwards.

        {
                File file("tmp_file.txt", "w");
                // First, write the number of characters that we're going to write.
                // This is the length of the alphabet, and that's actually pretty easy
                // to compute up-front.
                file.WriteChar('z' - 'a' + 1);

                // Write the alphabet to the file (this is based on the assumption
                // that 'char' is an ASCII character, but that's actually fairly
                // reasonable for a small example like this)
                for (char c = 'a'; c <= 'z'; c++)
                        file.WriteChar(c);

                // 'tmp_file.txt' is closed automatically by the destructor when 'file'
                // goes out of scope (which is right about now).
        }
        {
                RandomReadFile raFile("tmp_file.txt");
                tacFile(raFile);

                // Destructor will take care of things from here.
        }
}
