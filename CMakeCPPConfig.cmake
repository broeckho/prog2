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
# Use the C++11 standard. 
#----------------------------------------------------------------------------
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

#----------------------------------------------------------------------------
# Compile flags
#----------------------------------------------------------------------------
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" )
set( CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0"   )
include_directories( ${CMAKE_HOME_DIRECTORY}/main/cpp )

#----------------------------------------------------------------------------
# Platform dependent compile flags
#----------------------------------------------------------------------------
if( CMAKE_HOST_APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
endif()
if( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-braced-scalar-init " )
endif()

#----------------------------------------------------------------------------
# Standard math lib
#----------------------------------------------------------------------------
set( LIBS   ${LIBS}   m )

#----------------------------------------------------------------------------
# Boost
#----------------------------------------------------------------------------
set(BOOST_ROOT ${GOBELIJN_BOOST_ROOT})
find_package( Boost COMPONENTS filesystem thread date_time system REQUIRED )
include_directories(SYSTEM ${Boost_INCLUDE_DIRS} )
set( LIBS   ${LIBS} ${Boost_LIBRARIES} )

#----------------------------------------------------------------------------
# TCLAP Library (command line processing)
#----------------------------------------------------------------------------
include_directories( ${CMAKE_HOME_DIRECTORY}/main/resources/lib/tclap/include )

#----------------------------------------------------------------------------
# G3log
#----------------------------------------------------------------------------
include_directories( ${CMAKE_HOME_DIRECTORY}/main/resources/lib/g3log/src )
set( G3LOG_LIBRARIES			g3logger_shared) #lib_activeobject)
set( G3LOG_LIBRARIES_STATIC		g3logger-static) #lib_activeobject)

#----------------------------------------------------------------------------
# Linking.
#----------------------------------------------------------------------------
set( BUILD_SHARED_LIBS 	    ON 	 )
set( CMAKE_INSTALL_RPATH    ${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_LOCATION} )
SET( CMAKE_INSTALL_RPATH_USE_LINK_PATH   TRUE )

#############################################################################
