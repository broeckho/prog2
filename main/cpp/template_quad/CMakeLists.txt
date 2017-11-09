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
# Build / install / smoke test:
#============================================================================
foreach( EXEC	aquad_demo integral_demo )

	add_executable( ${EXEC}	${EXEC}.cpp abs_diff.cpp )	
	install( TARGETS ${EXEC} RUNTIME DESTINATION ${BIN_INSTALL_LOCATION} )			
	add_test( NAME ${EXEC}  
			COMMAND ${CMAKE_INSTALL_PREFIX}/${BIN_INSTALL_LOCATION}/$<TARGET_FILE_NAME:${EXEC}> )
	
endforeach()

#============================================================================
# Install headers.
#============================================================================
install( FILES	AdaptiveQuadrature.h AGL_Quadrature.h AQ_Util.h 
				CellCountViolation.h Convergence.h
				GaussLegendreRules.h Integral.h SimpleRules.h
		     DESTINATION 	${INCLUDE_INSTALL_LOCATION}/quad
		     PERMISSIONS 	OWNER_READ GROUP_READ WORLD_READ )

#############################################################################

