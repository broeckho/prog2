#############################################################################
#  This file is part of the gobelijn software.
#  Gobelijn is free software: you can redistribute it and/or modify it
#  under the terms of the GNU General Public License as published by the
#  Free Software Foundation, either version 3 of the License, or any later
#  version. Gobelijn is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
#  or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU General Public License for details. You should have received
#  a copy of the GNU General Public License along with the software. If not,
#  see <http://www.gnu.org/licenses/>.
#
#  Copyright 2017, 2018, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################

if(Boost_FOUND)
    add_subdirectory(abstract-factory)
else()
    message(WARNING "Boost not found: not including directory <abstract-factory>.")
endif()
add_subdirectory(demo-const)
add_subdirectory(demo-functor)
add_subdirectory(objtracer)
add_subdirectory(observer)
add_subdirectory(pimpl)
add_subdirectory(raii)
add_subdirectory(template_basics)
add_subdirectory(template_demo)
add_subdirectory(template_meta)
add_subdirectory(template_quad)
add_subdirectory(template_traits)
add_subdirectory(tracer)

#############################################################################
