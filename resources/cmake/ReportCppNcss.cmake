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
#	Executes the cppncss analysis provided the cppncss executable
#	can be found. Writes results to files named cppncss-<dirname>.xml 
#	in the target/reports/cppncss dir.
# 
#	Execution triggered via a make target named 
#       	cppncssdir-<dirname>
#	to analyze sources in dir <dirname>, or a global make target named 
#      		cppncss
# 	to analyze all sources.
# 	Note: dirname is the dir path relative to project root.
#
#############################################################################

#============================================================================
# Find cppncss.
#============================================================================
find_package( CppNcss )

#============================================================================
# Function to generate report; no-op function if cppncss not found.
#============================================================================
function( ReportCppNcss THIS_DIR )
	
	if( CPPNCSS_FOUND )
		
		# construct target name based on path relative to project root directory
		string( REPLACE ${CMAKE_SOURCE_DIR} "" RELDIR ${THIS_DIR} )
		string( REPLACE "/" "-" RELDIR ${RELDIR} )
		set( TARGET cppncssdir${RELDIR} )		
		add_custom_target( ${TARGET}
			${CPPNCSS_EXECUTABLE} -k -r -x -f=${CPPNCSS_DIR}/${TARGET}.xml -p=${CMAKE_SOURCE_DIR}/ ${THIS_DIR}  
			WORKING_DIRECTORY ${THIS_DIR} 
		)	
		add_dependencies( cppncss ${TARGET} )
		
		unset( RELDIR )	
		unset( TARGET )

	endif( CPPNCSS_FOUND )
		
endfunction( ReportCppNcss CPPNCSS )

#============================================================================
# Aggregate cppncss target.
#============================================================================
if( CPPNCSS_FOUND )

	add_custom_target( cppncss ALL )
	set( CPPNCSS_DIR ${CMAKE_CURRENT_BINARY_DIR}/reports/cppncss )
	file( MAKE_DIRECTORY ${CPPNCSS_DIR} )
	
endif( CPPNCSS_FOUND )

#############################################################################
