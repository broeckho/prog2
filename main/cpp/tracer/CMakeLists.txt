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
#  Copyright 2012, 2013, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################

#============================================================================
# Build / install for library:
#============================================================================                   
set( LIB	tracer )
set( SRC 	
		TracerOutput.cpp 
		BlockTracer.cpp 
		FunctionTracer.cpp 
		MemberTracer.cpp )
#----------------------------		
add_library( ${LIB} ${SRC} )
set_target_properties( ${LIB} PROPERTIES   SOVERSION 0   VERSION 0.0.0 )
target_link_libraries( ${LIB} 	        ${G3LOG_LIBRARIES} )
#----------------------------
install( TARGETS ${LIB}
		LIBRARY DESTINATION    ${LIB_INSTALL_LOCATION}
		ARCHIVE DESTINATION    ${LIB_INSTALL_LOCATION}
		PERMISSIONS    OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ )
install( FILES  
		BlockTracer.h 
		FunctionTracer.h 
		MemberTracer.h tracer.h
		TracerOutput.h
	            DESTINATION    ${INCLUDE_INSTALL_LOCATION}/misc
	            PERMISSIONS    OWNER_READ GROUP_READ WORLD_READ )
#----------------------------	
unset( SRC )
unset( LIB )
	

#============================================================================
# Build / install / smoke test for executables:
#============================================================================
set( EXEC	logdemo )
#----------------------------
add_executable( ${EXEC}	${EXEC}.cpp )
target_link_libraries( ${EXEC} tracer                   ${G3LOG_LIBRARIES} )
#----------------------------
install( TARGETS ${EXEC} RUNTIME DESTINATION ${BIN_INSTALL_LOCATION} )
#----------------------------
add_test( NAME ${EXEC}  
		    COMMAND ${CMAKE_INSTALL_PREFIX}/${BIN_INSTALL_LOCATION}/$<TARGET_FILE_NAME:${EXEC}> -n "jan" )
#----------------------------
unset( EXEC )

#############################################################################




