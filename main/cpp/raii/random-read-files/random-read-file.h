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
 * RAII random read file class.
 */

#include "../files/file.h"

#include <cstdio>
#include <vector>

namespace Raii {

/**
 * A file that supports random reads: reads that are based on an offset.
 * This differs from the typical sequential reads that are performed
 * when working with stream-based file APIs.
 * To avoid seeking, this class will store all previously read data in
 * a buffer. This class uses logical constness.
 * Note: this is a header-only class.
 */
class RandomReadFile
{
public:
        /**
         * Opens a random-read file at the given path.
         */
        RandomReadFile(const char* path) : m_file(path, "r"), m_buf() {}

        /*
         * Reads the 'char' at the given offset in this file.
         */
        char operator[](size_t Offset) const
        {
                // Fills the buffer vector with data, until the 'char' at the given
                // offset becomes available.
                // Note that this the enclosing method is marked 'const', though
                // the logic below clearly mutates the object's state.
                // That's perfectly fine, actually, because those changes to this
                // object's state are not visible to the outside world. Hence
                // the name 'logically const'.
                while (Offset >= m_buf.size()) {
                        int c = m_file.ReadChar();
                        if (c == EOF)
                                // We can't recover from this, because we're being
                                // asked to read beyond the end of the stream. The
                                // only way out is to throw an exception.
                                throw ReadError();

                        // Append the data to the buffer.
                        m_buf.push_back(c);
                }

                // Read the character from the buffer.
                return m_buf.at(Offset);
        }

private:
        // The file that is currently open. This member is mutable, even
        // when its enclosing object is (logically) 'const'.
        mutable File m_file;

        // A buffer for previously read data. This member is mutable, even
        // when its enclosing object is (logically) 'const'.
        mutable std::vector<char> m_buf;
};

} // end of namespace
