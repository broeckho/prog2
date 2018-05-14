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
#  Copyright 2017, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################
#
#  This file contains the C++ compile & link configuration.
#  Provides identical C++ configuration for the main/cpp 
#  and the test/ccp directories and subdirectories.
#
#############################################################################

#----------------------------------------------------------------------------
# Check CMAKE_BUILD_TYPE
#----------------------------------------------------------------------------
if( NOT (CMAKE_BUILD_TYPE MATCHES "Release" OR CMAKE_BUILD_TYPE MATCHES "Debug"))
    message(FATAL_ERROR  "========> CMAKE_BUILD_TYPE HAS TO MATCH EITHER Release OR Debug.")
endif()

#----------------------------------------------------------------------------
# Compile flags
#----------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wno-array-bounds")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast" )
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g"   )
include_directories(${CMAKE_HOME_DIRECTORY}/main/cpp)

#----------------------------------------------------------------------------
# Platform dependent compile flags
#----------------------------------------------------------------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_HOST_APPLE)
    add_definitions( -D__APPLE__ )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-unused-private-field")
    #
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND NOT CMAKE_HOST_APPLE )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-command-line-argument -Wno-self-assign")
    add_definitions(-D__extern_always_inline=inline)
    #
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized")
endif()

#----------------------------------------------------------------------------
# Standard math lib
#----------------------------------------------------------------------------
set( LIBS   ${LIBS}   m )

#----------------------------------------------------------------------------
# Boost
#----------------------------------------------------------------------------
#set(BOOST_ROOT ${GOBELIJN_BOOST_ROOT})
#set(Boost_NO_SYSTEM_PATHS ${GOBELIJN_BOOST_NO_SYSTEM_PATHS})
find_package(Boost COMPONENTS filesystem thread date_time system QUIET)
if(Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
    set(LIBS   ${LIBS} ${Boost_LIBRARIES})
endif()

#----------------------------------------------------------------------------
# TCLAP Library (command line processing)
#----------------------------------------------------------------------------
include_directories( ${CMAKE_HOME_DIRECTORY}/main/resources/lib/tclap/include)

#----------------------------------------------------------------------------
# G3log
#----------------------------------------------------------------------------
include_directories(${CMAKE_HOME_DIRECTORY}/main/resources/lib/g3log/src)
set(G3LOG_LIBRARIES            g3logger_shared) #lib_activeobject)
set(G3LOG_LIBRARIES_STATIC     g3logger-static) #lib_activeobject)

#----------------------------------------------------------------------------
# Linking.
#----------------------------------------------------------------------------
set(BUILD_SHARED_LIBS 	    ON)
set(CMAKE_INSTALL_RPATH    ${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_LOCATION})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH   TRUE)

#############################################################################
