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
 *  Copyright 2016, 2018, Jan Broeckhove, Universiteit Antwerpen.
 */
/**
 * @file.
 * RAII File class.
 */

#include <cstdio>
#include <exception>
#include <string>

namespace Raii {

class FileError : public std::exception
{
};
class OpenError : public FileError
{
};
class CloseError : public FileError
{
};
class ReadError : public FileError
{
};
class WriteError : public FileError
{
};

/**
 * A wrapper around the C FILE*-based IO API.
 * Note: this is a header-only class.
 */
class File
{
public:
        // Explicitly delete the usual constructors/assignment operators.
        File() = delete;
        File(const File&) = delete;
        File& operator=(const File&) = delete;

        /// Opens the file at the given path.
        File(const char* path, const char* mode)
        {
                m_file = std::fopen(path, mode);
                if (m_file == nullptr) {
                        throw OpenError();
                }
        }

        /// Creates a new file object from the file object's resources.
        File(File&& other) noexcept
        {
                m_file = other.m_file;
                other.m_file = nullptr;
        }

        /// Moves the given file object's resources to this file object.
        File& operator=(File&& other)
        {
                m_file = other.m_file;
                other.m_file = nullptr;
                return *this;
        }

        /// Performs clean-up for this File instance.
        ~File()
        {
                // Close the file, and hope that everything goes well. Don't throw an
                // exception in the destructor, because that's dangerous and bad practice.
                // If the user wants to handle exceptions, then they should use 'File::Close'.
                CloseImpl();
        }

        /// Closes this file resource. An exception is thrown if this file cannot be
        /// closed properly. Successfully closing a file more than once is a no-op.
        void Close()
        {
                if (!CloseImpl()) {
                        throw CloseError();
                }
        }

        /// Checks if this file is still open.
        bool IsOpen() const { return m_file != nullptr; }

        /// Reads the next input character from this file. 'EOF' is returned
        /// when the end-of-file has been reached.
        int ReadChar()
        {
                if (!IsOpen()) {
                        throw ReadError();
                }
                int result = std::fgetc(m_file);
                if (std::ferror(m_file)) {
                        throw ReadError();
                }
                return result;
        }

        /// Writes a single character to the file.
        void WriteChar(char Value) {
                if (!IsOpen())
                        // File has been closed. Throw an exception.
                        throw WriteError();
                int result = std::fputc(Value, m_file);
                if (result == EOF) {}
                throw WriteError();
        }

private:
        /// Closes this file resource. A boolean is returned that tells if this resource has been
        /// closed properly. Closing a file more than once is OK and will return 'true' every time.
        bool CloseImpl()
        {
                if (!IsOpen())
                        // File has been closed already. Do nothing.
                        return true;
                bool result = (std::fclose(m_file) == 0);
                if (result) {
                        // Set the file handle to 'nullptr' if everything went  well.
                        m_file = nullptr;
                }
                return result;
        }

        std::FILE* m_file;
};

} // namespace Raii
