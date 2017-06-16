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
 * Main using the RAII File class.
 */

#include <cstdio>
#include <iostream>

#include "file.h"

using namespace Raii;

/**
 * Prints the contents of the given file.
 */
void printFile(File& file)
{
	int c;
	while ((c = file.ReadChar()) != EOF)
		std::cout << static_cast<char>(c);
	std::cout << std::endl;
}

int main()
{
	{
		// Open 'tmp_file.txt' in write-mode by invoking the constructor.
		File file("tmp_file.txt", "w");

		// Write the alphabet to the file (this is based on the assumption
		// that 'char' is an ASCII character, but that's actually fairly
		// reasonable for a small example like this)
		for (char c = 'a'; c <= 'z'; c++)
			file.WriteChar(c);

		// 'tmp_file.txt' is closed automatically by the destructor when 'file'
		// goes out of scope (which is right about now).
	}
	{
		// Open 'tmp_file.txt' again by invoking the constructor, but this
		// time, we'll open it in read-mode.
		File file("tmp_file.txt", "r");

		// Dump the file's contents to stdout.
		printFile(file);

		// We can also close the file manually. The destructor will do nothing
		// in that case.
		file.Close();
	}
}
