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
# Build & install & smoke test :
#============================================================================
foreach( EXEC	max0 max1 max1-partial max2 max3 max3-bis
				stack1test stack2test stack3test stack4test stack5test
				stack6test stack7test )

	add_executable( ${EXEC}	${EXEC}.cpp ${EXTRA_SRC_${EXEC}} )
	install( TARGETS ${EXEC} RUNTIME DESTINATION ${BIN_INSTALL_LOCATION} )
	add_test( NAME ${EXEC}  
			COMMAND  ${CMAKE_INSTALL_PREFIX}/${BIN_INSTALL_LOCATION}/${EXEC} )
			
endforeach()

#############################################################################


