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
 *  Copyright 2012, Jan Broeckhove, CoMP/UA.
 */
/**
 * @file
 * Demo for generic programming.
 */

#include "RandInt.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>

using std::cout;
using std::endl;
using std::exception;
using std::string;

namespace {

/** Initialize a container with random ints in [1, 100]. */
template <typename C>
void SimpleRandInit(C& c)
{
        RandInt r(1, 100);
        for (auto it = c.begin(); it != c.end(); ++it) {
                *it = r();
        }
}

/** Sum all the elements of a container. */
template <typename C>
typename C::value_type Sum(const C& c)
{
        typename C::value_type val = typename C::value_type();
        for (auto it = c.cbegin(); it != c.cend(); ++it) {
                val += *it;
        }
        return val;
}

/** Bin identical elements container. */
template <typename C>
std::map<typename C::value_type, unsigned int> Bin(C const& c)
{
        std::map<typename C::value_type, unsigned int> m;
        for (auto it = c.cbegin(); it != c.cend(); ++it) {
                m[*it]++;
        }
        return m;
}

/** Sum all the elements of a sequence. */
template <typename It>
typename It::value_type Sum(It first, It last)
{
        typename It::value_type val = typename It::value_type();
        for (It it = first; it != last; ++it) {
                val += *it;
        }
        return val;
}

/** Bin identical elements in a sequence. */
template <typename It>
std::map<typename It::value_type, unsigned int> Bin(It first, It last)
{
        std::map<typename It::value_type, unsigned int> m;
        for (It it = first; it != last; ++it) {
                m[*it]++;
        }
        return m;
}

/** Accumulate values of type T */
template <typename T>
class Accumulator
{
public:
        ///
        explicit Accumulator(T t = T()) : m_accum(t) {}

        ///
        T operator()(T t) { return (m_accum += t); }

        ///
        T operator()() const { return m_accum; }

private:
        T m_accum;
};

/** Increment a value of type T */
class Incrementor
{
public:
        ///
        explicit Incrementor(unsigned int n) : m_num(n) {}

        ///
        template <typename T>
        T operator()(T t)
        {
                for (unsigned int i = 1; i <= m_num; i++) {
                        t++;
                }
                return t;
        }

private:
        unsigned int m_num;
};

/** Print pairs. */
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::pair<T, U> p)
{
        operator<<(out.operator<<(p.first), " - ");
        (out.operator<<(p.second)).operator<<(endl);
        return out;
}

/** Print container. */
template <typename C>
std::ostream& Printer(std::ostream& out, C const& c)
{
        for (auto it = c.cbegin(); it != c.cend(); ++it) {
                out << " " << *it;
        }
        return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v)
{
        return Printer<std::vector<T>>(os, v);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::list<T> const& v)
{
        return Printer<std::list<T>>(os, v);
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::map<T, U> const& v)
{
        return Printer<std::map<T, U>>(os, v);
}

} // namespace

int main()
{
        string marker = "\n------------------------------------\n";
        cout << std::boolalpha;
        // block 1
        {
                cout << marker << "simpleRandInit for vector of 10 int:" << endl;
                std::vector<double> v(10);
                SimpleRandInit(v);
                cout << v << endl << "sum: " << Sum(v) << endl;
        }
        // block 2
        {
                cout << marker << "bin processes list of 15 int:" << endl;
                std::list<int> v(15);
                SimpleRandInit(v);
                cout << v << endl << "sum: " << Sum(v.cbegin(), v.cend()) << endl << Bin(v) << endl;
        }
        // block 3
        {
                cout << marker << "bin processes vector of 10 double:" << endl;
                std::vector<double> v(10);
                generate(v.begin(), v.end(), RandInt(7, static_cast<unsigned int>(v.size())));
                cout << v << endl << Bin(v.begin(), v.end()) << endl;
        }
        // block 4
        {
                cout << marker << "find in list of 15 int:" << endl;
                std::list<int> v(15);
                SimpleRandInit(v);
                cout << v << endl;
                auto it1 = find(v.cbegin(), v.cend(), 6);
                auto it2 = find(it1, v.cend(), 14);
                auto it3 = find(it1, it2, 13);
                cout << (it3 != it2) << endl;
        }
        // block 5
        {
                cout << marker << "functor to accumulate sequence:" << endl;
                std::vector<int> v(10);
                std::list<int> l(12);
                generate(v.begin(), v.end(), RandInt(8, static_cast<unsigned int>(v.size())));
                generate(l.begin(), l.end(), RandInt(6, static_cast<unsigned int>(v.size())));
                Accumulator<int> a;
                a = for_each(v.begin(), v.end(), a);
                cout << v << endl << a() << endl;
                Incrementor b(2);
                for_each(l.begin(), l.end(), b);
                cout << l << endl << a() << endl;
        }
        // block 6
        {
                cout << marker << "functor to transform sequence:" << endl;
                std::vector<int> v(8);
                std::list<int> l(8);
                generate(v.begin(), v.end(), RandInt(3, static_cast<unsigned int>(v.size())));
                cout << "transform out of place: " << endl;
                transform(v.begin(), v.end(), l.begin(), Incrementor(2));
                cout << v << endl << l << endl;
                cout << "transform in place: " << endl;
                transform(v.begin(), v.end(), v.begin(), Incrementor(5));
                cout << v << endl;
        }

        return 0;
}
