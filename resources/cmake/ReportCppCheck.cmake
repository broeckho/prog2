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
#	Executes the cppcheck analysis provided the cppcheck executable
#	can be found. Writes results to files named cppcheckdir-<dirname>.xml 
#	in the target/reports/cppcheck dir.
# 
#	Execution triggered via a make target named 
#       	cppcheckdir-<dirname>
#	to analyze sources in dir <dirname>, or a global make target named 
#       	cppcheck
#	to analyze all sources.
#	Note: dirname is the dir path relative to project root.
#
#############################################################################

#============================================================================
# CppCheck reporting.
#============================================================================
find_package( cppcheck )

#============================================================================
# Function to generate report; no-op function if cppcheck not found.
#============================================================================
function( ReportCppCheck THIS_DIR )
	
	if( CPPCHECK_FOUND )
		
		# construct target name based on path relative to project root directory
		string( REPLACE ${CMAKE_SOURCE_DIR} "" RELDIR ${THIS_DIR} )
		string( REPLACE "/" "-" RELDIR ${RELDIR} )
		set( TARGET cppcheckdir${RELDIR} )		
				
		add_custom_target( ${TARGET}
			${CPPCHECK_EXECUTABLE} --xml --enable=all --suppress=missingInclude -I${CMAKE_SOURCE_DIR}/main/cpp ${THIS_DIR} 2> ${CPPCHECK_DIR}/${TARGET}.xml  
			WORKING_DIRECTORY ${THIS_DIR} 
		)		
		add_dependencies( cppcheck ${TARGET} )
		
		unset( RELDIR )	
		unset( TARGET  )

	endif( CPPCHECK_FOUND )
		
endfunction( ReportCppCheck THIS_DIR )

#============================================================================
# Aggregate cppcheck target.
#============================================================================
if( CPPCHECK_FOUND )

	add_custom_target( cppcheck ALL )
	set( CPPCHECK_DIR ${CMAKE_CURRENT_BINARY_DIR}/reports/cppcheck )
	file( MAKE_DIRECTORY ${CPPCHECK_DIR} )
	
endif( CPPCHECK_FOUND )

#############################################################################