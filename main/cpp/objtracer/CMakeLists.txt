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
# Build library:
#============================================================================
set( LIB	demobj )
set( SRC 	
		Bicycle.cpp Body.cpp Engine.cpp FreightRoadVehicle.cpp LandVehicle.cpp
		Motorcycle.cpp PassengerRoadVehicle.cpp Person.cpp 
		RoadVehicle.cpp SailBoat.cpp Unicycle.cpp 
		Vehicle.cpp WaterVehicle.cpp Wheel.cpp )
#----------------------
include_directories( ${LOG_SRC} )
add_library( ${LIB}        ${SRC}  )
set_target_properties( ${LIB} PROPERTIES    SOVERSION	0     VERSION 0.0.0 )

if( APPLE )
	set_target_properties( ${LIB} PROPERTIES 
			INSTALL_NAME_DIR ${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_LOCATION} )
endif( APPLE )
target_link_libraries( ${LIB} 		tracer )
#-----------------------
install( TARGETS ${LIB} LIBRARY 
                DESTINATION 	${LIB_INSTALL_LOCATION}
                PERMISSIONS 	OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ )	 
install( FILES 
		Bicycle.h demobj.h Engine.h FreightRoadVehicle.h
		LandVehicle.h Motorcycle.h 
		PassengerRoadVehicle.h
		Person.h RoadVehicle.h SailBoat.h Vehicle.h 
		WaterVehicle.h Wheel.h
                DESTINATION 	${INCLUDE_INSTALL_LOCATION}/objtracer
                PERMISSIONS 	OWNER_READ GROUP_READ WORLD_READ )
#---------------------
unset( SRC )
unset( LIB )

#============================================================================
# Build / install / smoke test for executables:
#============================================================================
set( EXEC	objtracer )
set( SRC
		${EXEC}.cpp exam01.cpp fcalls.cpp mbasics.cpp
		mcopy.cpp vbasics.cpp vpoly.cpp 
)
#---------------------
include_directories( ${LOG_SRC} )
add_executable( ${EXEC}	   ${SRC} )
target_link_libraries( ${EXEC} demobj tracer ${G3LOG_LIBRARIES}  )

#---------------------
install( TARGETS ${EXEC} RUNTIME DESTINATION 	${BIN_INSTALL_LOCATION} )
#------------------------
set( PROJECTS     exam01 fcalls mbasics mcopy vbasics vpoly )
foreach (PROJ ${PROJECTS} )

		add_test( NAME  objtracer_${PROJ}
				COMMAND ${CMAKE_INSTALL_PREFIX}/${BIN_INSTALL_LOCATION}/$<TARGET_FILE_NAME:objtracer>
				--exec ${PROJ} )
		
endforeach()
#---------------------
unset( SRC )
unset( EXEC )
unset( PROJECTS )

#############################################################################


