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
	
#============================================================================
# Top level custom targets:
#============================================================================
set( TESTS_LOC ${CMAKE_INSTALL_PREFIX}/${TESTS_INSTALL_LOCATION} )
unset( CTEST_VERBOSE_OPTION )
if( GOBELIJN_VERBOSE_TESTING )
	set( CTEST_VERBOSE_OPTION "-V" )
endif()
	
add_custom_target( run_ctest
	COMMAND ${CMAKE_COMMAND} -E make_directory ${TESTS_LOC}
	COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} 
			ctest ${CTEST_VERBOSE_OPTION} -O ${TESTS_LOC}/ctests_core.txt
)

#============================================================================
# Add subdirectories:
#============================================================================
add_subdirectory( cpp       )
add_subdirectory( resources )

#############################################################################
