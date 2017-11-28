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
# Google test (src in resources/lib/gtest)
#============================================================================
include_directories( ${CMAKE_HOME_DIRECTORY}/test/resources/lib/gtest/ )
add_definitions( -DGTEST_LANG_CXX11 )

#============================================================================
# Build & install gtester
#============================================================================
set( G_OUTPUT_DIR  ${CMAKE_INSTALL_PREFIX}/${TESTS_INSTALL_LOCATION} )
set( EXEC  gtestdriver )
set( SRC              
	main.cpp
	UnitCircular.cpp
	UnitCumulativeRecords.cpp
	UnitConstCircular.cpp
	UnitQuad.cpp
	UnitRecords.cpp
	UnitSegmentedVector.cpp
)

#-----------------
add_executable( ${EXEC}  ${SRC} )
target_link_libraries( ${EXEC} ${LIBS} gtest pthread )
 
#-----------------        
install( TARGETS ${EXEC} RUNTIME DESTINATION   ${BIN_INSTALL_LOCATION} )
 
#-----------------      
add_test( NAME	${EXEC}
		WORKING_DIRECTORY  ${G_OUTPUT_DIR}
		COMMAND  ${CMAKE_INSTALL_PREFIX}/${BIN_INSTALL_LOCATION}/${EXEC}
							--shuffle 
							--gtest_output=xml:${G_OUTPUT_DIR}/${EXEC}.xml 
		)

#-----------------
unset( G_OUTPUT_DIR )  
unset( EXEC         )
unset( SRC          )

#############################################################################

