#ifndef INC_FUNCTION_MAP_H
#define INC_FUNCTION_MAP_H
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
 *  Copyright 2013, Jan Broeckhove, UA/CoMP.
 */
/**
 * @file
 * Implementation of a map to hold function. I'm assuming fairly few
 * operations on the map after initialization. Developed to use it to
 * hold factory functions (i.e. function objects that encapsulate the
 * creation of other objects. You can switch between std::function or
 * boost::function. I intend to use this with the boost.functional
 * factory and with my present boost/gcc combo the assignment of
 * e.g. function<A*(int)> f = factory<A*>() succeeds for boost::function
 * but fails for std::function.
 */

#include <boost/function.hpp>
#include <boost/functional/factory.hpp>
#include <functional>
#include <initializer_list>
#include <list>
#include <map>
#include <string>
#include <utility>

namespace UA_CoMP {
namespace Util {

template <typename T>
struct BadFunctionCallType
{
};

template <typename S>
struct BadFunctionCallType<std::function<S>>
{
        typedef std::bad_function_call type;
};

template <typename S>
struct BadFunctionCallType<boost::function<S>>
{
        typedef boost::bad_function_call type;
};

template <typename S, template <typename> class F = std::function>
class FunctionMap
{
public:
        // Type of function stored in the map.
        typedef F<S> FunctionType;

        // Type of bad_function_call exception
        typedef typename BadFunctionCallType<FunctionType>::type BadFunctionCallType;

private:
        ///
        typedef std::map<const std::string, const FunctionType> MapType;

public:
        /// Construct an empty map.
        FunctionMap() {}

        /// Construct map from initializer_list.
        FunctionMap(std::initializer_list<typename MapType::value_type> l) : m_map(l) {}

        /// Return function for given name.
        FunctionType Get(const std::string& name) const
        {
                return (m_map.count(name) != 0) ? m_map.at(name) : FunctionType();
        }

        /// Check validity.
        bool IsValid(const std::string& name) const { return (m_map.count(name) != 0) && (m_map.at(name)); }

        /// Register.
        bool Register(const std::string& name, const FunctionType& f)
        {
                bool status = false;
                if ((m_map.count(name) == 0) && (f)) {
                        m_map.insert(make_pair(name, f));
                        status = true;
                }
                return status;
        }

        /// List.
        std::list<std::string> List() const
        {
                std::list<std::string> l;
                for (const auto& e : m_map) {
                        l.push_back(e.first);
                }
                return l;
        }

private:
        MapType m_map;
};

} // namespace
} // namespace

