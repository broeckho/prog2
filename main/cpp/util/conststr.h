#pragma once
/*
 *  This file is part of the indismo software.
 *  It is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *  The software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with the software. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2014, L. Willem, J. Broeckhove, S. Stijven, UAntwerpen.
 */
/**
 * @file
 * Constexpr string construct.
 */
#include <stdexcept>
#include <string>

class conststr
{
public:
        template <std::size_t N>
        constexpr conststr(const char (&a)[N]) : m_p(a), m_size(N - 1)
        {
        }

        // constexpr functions signal errors by throwing exceptions from operator ?:
        constexpr char operator[](std::size_t n) const { return n < m_size ? m_p[n] : throw std::out_of_range(""); }

        constexpr std::size_t size() const { return m_size; }

        std::string to_string() const { return m_p; }

private:
        const char* m_p;
        std::size_t m_size;
};

