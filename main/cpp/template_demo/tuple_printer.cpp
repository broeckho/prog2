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
 *  Copyright 2016, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Varyadic template tuple_printer.
 */

#include <iostream>

using namespace std;

// Helper function to print a tuple of any size; recurses on N.
template <class Tuple, std::size_t N>
struct TuplePrinter
{
        static void print(const Tuple& t)
        {
                cout << "\n\t ----> \n\t N = " << N << "  ; " << __PRETTY_FUNCTION__ << "\n\t <----- \n" << endl;
                TuplePrinter<Tuple, N - 1>::print(t);
                cout << ", " << std::get<N - 1>(t);
        }
};

// Helper function to print a tuple of size 1; ends recursion on N.
template <class Tuple>
struct TuplePrinter<Tuple, 1>
{
        static void print(const Tuple& t)
        {
                cout << "\n\t ----> \n\t N = 1 "
                     << "  ; " << __PRETTY_FUNCTION__ << "\n\t <----- \n"
                     << endl;
                cout << std::get<0>(t);
        }
};

// Tuple printer.
template <class... Args>
void print(const std::tuple<Args...>& t)
{
        cout << "(";
        TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
        cout << ")\n";
}

// Demo.
int main()
{
        const auto t1 = make_tuple(6, 3.14, 'a', "haha!");
        cout << "\nFirst tuple: " << endl;
        print(t1);

        const auto t2 = make_tuple(string("7.4"), string("aaa"));
        cout << "\nSecond tuple: " << endl;
        print(t2);

        // BUT THIS DOES NOT WORK!
        // const auto t3 = make_tuple(t1, t2);
        // cout << "\nThird tuple: " << endl;
        // print(t3);

        return 0;
}
