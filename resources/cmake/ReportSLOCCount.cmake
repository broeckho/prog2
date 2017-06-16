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
#	Executes the sloccount analysis provided the sloccount executable
#	can be found. Writes results to files named sloccountdir-<dirname>.xml 
#	in the target/reports/sloccount dir.
# 
#	Execution triggered via a make target named 
#       	sloccountdir-<dirname>
#	to analyze sources in dir <dirname>, or a global target named 
#       	sloccount
#	to analyze all sources.
# 	Note: dirname is the dir path relative to project root.
#
#############################################################################

#============================================================================
# Find sloccount.
#============================================================================
find_package( SLOCCount )

#============================================================================
# Function to generate report; no-op function if sloccount not found.
#============================================================================
function( ReportSLOCCount THIS_DIR )
	
	if( SLOCCOUNT_FOUND )
	
		# construct target name based on path relative to project root directory
		string( REPLACE ${CMAKE_SOURCE_DIR} "" RELDIR ${THIS_DIR} )
		string( REPLACE "/" "-" RELDIR ${RELDIR} )
		set( TARGET sloccountdir${RELDIR} )		
		
		add_custom_target( ${TARGET}
			${SLOCCOUNT_EXECUTABLE} --wide --details ${THIS_DIR} > ${SLOCCOUNT_DIR}/${TARGET}.sc
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
		)	
		add_dependencies( sloccount ${TARGET} )
		
		unset( RELDIR )	
		unset( TARGET )

	endif( SLOCCOUNT_FOUND )
		
endfunction( ReportSLOCCount THIS_DIR )

#============================================================================
# Aggregate sloccount target.
#============================================================================	
if( SLOCCOUNT_FOUND )

	add_custom_target( sloccount ALL )
	set( SLOCCOUNT_DIR ${CMAKE_CURRENT_BINARY_DIR}/reports/sloccount )
	file( MAKE_DIRECTORY ${SLOCCOUNT_DIR} )
	
endif( SLOCCOUNT_FOUND )

#############################################################################
