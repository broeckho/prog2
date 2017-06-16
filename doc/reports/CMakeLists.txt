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
# Temporary reports directory:
#============================================================================
file( MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/reports )

#============================================================================
# Additional CMake modules:
#============================================================================
include( ReportCppCheck  )
include( ReportCppNcss   )
include( ReportSLOCCount )

#============================================================================
# Cpp related reports
#============================================================================
ReportCppCheck( ${CMAKE_SOURCE_DIR}/main/cpp )
ReportCppNcss(  ${CMAKE_SOURCE_DIR}/main/cpp )

#============================================================================
# SLOCcount reports
#============================================================================
ReportSLOCCount( ${CMAKE_SOURCE_DIR}/main )

#============================================================================
# Install
#============================================================================
install( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/reports
	DESTINATION             ${DOC_INSTALL_LOCATION} 
	FILE_PERMISSIONS        OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ 
	DIRECTORY_PERMISSIONS   OWNER_READ OWNER_WRITE OWNER_EXECUTE
				GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

#############################################################################