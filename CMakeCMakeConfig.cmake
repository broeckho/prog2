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
#  Copyright 2012, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################
#
#	This file contains CMake configuration settings.
#
#############################################################################

#============================================================================
# This file contains configuration for the CMake tool itself.
#============================================================================
set( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS 	TRUE )
set( CMAKE_COLOR_MAKEFILE               ON   )
set( CMAKE_VERBOSE_MAKEFILE             OFF  )
enable_testing()

#============================================================================
# Additional CMake modules:
#============================================================================
list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/resources/cmake/" )

#============================================================================
# Macro sets NAME to VALUE iff the NAME has not been defined yet:
#============================================================================
MACRO(set_if_null NAME VALUE)
        if( NOT DEFINED ${NAME} OR "${NAME}" STREQUAL "" )
                set( ${NAME}    "${VALUE}" )
        endif()
ENDMACRO(set_if_null)

#############################################################################
