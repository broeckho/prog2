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
#        Local (at your site or for you personally) configuration.
#        We adopted this approach because IDE's do not
#        allways pick up your personalized environment variables.
#
#############################################################################

message(STATUS "\nReading configuration info from CMakeLocal.cmake! \n")

#============================================================================
# MACRO (WARNING: CLion overrides the setting of CMAKE_BUILD_TYPE)
#============================================================================
set(GOBELIJN_INCLUDE_DOC      FALSE)

if(NOT DEFINED CMAKE_CXX_COMPILER)
    set(GOBELIJN_COMPILER_ID      GNU)
    #set(GOBELIJN_COMPILER_ID      Clang)
    #set(GOBELIJN_COMPILER_ID      Apple)
endif()
if(NOT DEFINED CMAKE_BUILD_TYPE)
    #set(CMAKE_BUILD_TYPE "Debug")
endif()

#============================================================================
# To help find modules.
#============================================================================
if(APPLE)
    set(CMAKE_PREFIX_PATH "/opt/local/Library/Frameworks/Python.framework/Versions/3.6;$ENV{PATH}")
endif()
# For Ubuntu 14.04
set(Python_ADDITIONAL_VERSIONS 3.4)

#============================================================================
# Install dir.
#============================================================================
execute_process(COMMAND git rev-list HEAD --count
    OUTPUT_VARIABLE GOBELIJN_GIT_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_INSTALL_PREFIX  $ENV{HOME}/opt/stride-${GOBELIJN_GIT_LABEL})

#============================================================================
# Compiler & Boost.
#============================================================================
if(LINUX)
    if(GOBELIJN_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_C_COMPILER   /usr/bin/gcc  CACHE PATH "C compiler path")
        set(CMAKE_CXX_COMPILER /usr/bin/g++  CACHE PATH "CXX compiler path")
    elseif(GOBELIJN_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_C_COMPILER   /usr/bin/clang    CACHE PATH "C compiler path")
        set(CMAKE_CXX_COMPILER /usr/bin/clang++  CACHE PATH "CXX compiler path")
    endif()
endif()
#
if(APPLE)
    if(GOBELIJN_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_C_COMPILER   /opt/local/bin/gcc  CACHE PATH "C compiler path")
        set(CMAKE_CXX_COMPILER /opt/local/bin/g++  CACHE PATH "CXX compiler path")
    elseif(GOBELIJN_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_C_COMPILER   /opt/local/bin/clang   CACHE PATH "C compiler path")
        set(CMAKE_CXX_COMPILER /opt/local/bin/clang++ CACHE PATH "CXX compiler path")
    elseif(GOBELIJN_COMPILER_ID STREQUAL "Apple")
        set(CMAKE_C_COMPILER   /usr/bin/cc   CACHE PATH "C compiler path")
        set(CMAKE_CXX_COMPILER /usr/bin/c++  CACHE PATH "CXX compiler path")
    endif()
endif()

#============================================================================
# Compiler & Boost.
#============================================================================
if(LINUX)
    set(GOBELIJN_BOOST_ROOT "/opt/boost/gcc/boost_1_66_0/")
    set(GOBELIJN_BOOST_NO_SYSTEM_PATHS ON)
endif()
#
if(APPLE)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR GOBELIJN_COMPILER_ID STREQUAL "GNU")
        set(BOOST_ROOT /opt/boost-1.67.0)
        set(BOOST_NO_SYSTEM_PATHS ON)
    else()
        set(BOOST_ROOT /opt/local)
        set(BOOST_NO_SYSTEM_PATHS ON)
    endif()
endif()

#############################################################################
