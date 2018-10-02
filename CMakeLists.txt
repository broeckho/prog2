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
#  CMakeLists.txt for the whole project.
#
#############################################################################

#============================================================================
# Configuring Make and local settings for project.
#============================================================================
cmake_minimum_required(VERSION 3.5)
include(CMakeConfig.cmake)
include(CMakeLocal.cmake OPTIONAL)

#============================================================================
# Project name.
#============================================================================
project(gobelijn)
if(CMAKE_VERSION VERSION_GREATER 3)
	cmake_policy(SET CMP0042 NEW)
endif()

#============================================================================
# Install directory definitions.
#============================================================================
set_if_null(BIN_INSTALL_LOCATION	    bin   )
set_if_null(LIB_INSTALL_LOCATION	    lib   )
set_if_null(INCLUDE_INSTALL_LOCATION    include)
set_if_null(DATA_INSTALL_LOCATION	    data  )
set_if_null(DOC_INSTALL_LOCATION	    doc   )
set_if_null(TESTS_INSTALL_LOCATION	    tests )

#============================================================================
# Git revision status.
#============================================================================
find_package(Git QUIET)
if(GIT_FOUND)
    GIT_WC_INFO(${CMAKE_SOURCE_DIR} GOBELIJN)
else()
    # This is done to eliminate blank output of undefined CMake variables.
    set(GIT_FOUND FALSE)
    set(GOBELIJN_WC_REVISION_HASH      "0000000")
    set(GOBELIJN_WC_LAST_CHANGED_DATE  "0000 0000 0000")
endif()

#============================================================================
# Configuration C++ compile & link deferred to separate file.
#============================================================================
include(CMakeCPP.cmake)

#============================================================================
# Configuration for DOC: DOXYGEN
#============================================================================
if(GOBELIJN_INCLUDE_DOC)
    find_package( Doxygen)
endif()

#============================================================================
# Add subdirs (excluding doc dir avoids building doc in development):
#============================================================================
add_subdirectory(main)
add_subdirectory(test)
if(GOBELIJN_INCLUDE_DOC)
	add_subdirectory(doc)
endif()

#============================================================================
# Overview report:
#============================================================================
message(STATUS " ")
if ( GIT_FOUND )
    message(STATUS "------> Git revision id: ${GOBELIJN_WC_REVISION_HASH} "       )
    message(STATUS "------> Git commit date: ${GOBELIJN_WC_LAST_CHANGED_DATE} "   )
    message(STATUS " "  )
endif()
message(STATUS "------> Settings and options: ")
message(STATUS "------> GOBELIJN_INCLUDE_DOC        : ${GOBELIJN_INCLUDE_DOC} "     )
#
message(STATUS " ")
message(STATUS "------> CMAKE_SYSTEM                : ${CMAKE_SYSTEM} "             )
message(STATUS "------> CMAKE_SYSTEM_VERSION        : ${CMAKE_SYSTEM_VERSION} "     )
message(STATUS "------> CMAKE_SYSTEM_PROCESSOR      : ${CMAKE_SYSTEM_PROCESSOR} "   )
#
message( STATUS " " )
message( STATUS "------> CMAKE_VERSION               : ${CMAKE_VERSION} "          )
message( STATUS "------> CMAKE_PREFIX_PATH           : ${CMAKE_PREFIX_PATH} "      )
message( STATUS "------> ENVIRONMENT PATH            : $ENV{PATH} "                )
#
message(STATUS " ")
message(STATUS "------> CMAKE_BUILD_TYPE            : ${CMAKE_BUILD_TYPE} "         )
message(STATUS "------> CMAKE_BINARY_DIR            : ${CMAKE_BINARY_DIR} "         )
message(STATUS "------> CMAKE_INSTALL_PREFIX        : ${CMAKE_INSTALL_PREFIX}"      )
message(STATUS "------> CMAKE_CXX_COMPILER          : ${CMAKE_CXX_COMPILER}"        )
message(STATUS "------> CMAKE_CXX_COMPILER_ID       : ${CMAKE_CXX_COMPILER_ID}"     )
message(STATUS "------> CMAKE_CXX_COMPILER_VERSION  : ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "------> CMAKE_CXX_FLAGS             : ${CMAKE_CXX_FLAGS}"           )
if(CMAKE_BUILD_TYPE MATCHES "^[Rr]elease$")
	message(STATUS "------> CMAKE_CXX_FLAGS_RELEASE     : ${CMAKE_CXX_FLAGS_RELEASE}")
endif()
if(CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug$")
	message(STATUS "------> CMAKE_CXX_FLAGS_DEBUG       : ${CMAKE_CXX_FLAGS_DEBUG}"  )
endif()
#
message(STATUS " ")
message(STATUS "------> Boost_FOUND                 : ${Boost_FOUND} "              )
message(STATUS "------> Boost_VERSION               : ${Boost_VERSION} "            )
message(STATUS "------> Boost_INCLUDE_DIRS          : ${Boost_INCLUDE_DIRS} "       )
message(STATUS "------> Boost_LIBRARIES             : ${Boost_LIBRARIES} "          )
#
message( STATUS "" )
if ( GOBELIJN_INCLUDE_DOC )
    message( STATUS "------> DOXYGEN_FOUND               : ${DOXYGEN_FOUND} "          )
    message( STATUS "------> DOXYGEN_DOT_FOUND           : ${DOXYGEN_DOT_FOUND} "      )
    if ( DOXYGEN_FOUND )
        message( STATUS "------> DOXYGEN_EXECUTABLE          : ${DOXYGEN_EXECUTABLE} " )
        message( STATUS "------> DOXYGEN_VERSION             : ${DOXYGEN_VERSION} "    )
    endif()
    if ( DOXYGEN_DOT_FOUND )
        message( STATUS "------> DOXYGEN_DOT_EXECUTABLE      : ${DOXYGEN_DOT_EXECUTABLE} " )
    endif()
endif()
#
message(STATUS "")
message(STATUS "Report complete.")

#############################################################################
