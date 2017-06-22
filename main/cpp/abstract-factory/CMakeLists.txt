#============================================================================
# Build & install :
#============================================================================
# Only build this example if the boost libraries have been found.
if( Boost_FOUND )

	set( EXEC abstract-factory )
	include_directories( ${Boost_INCLUDE_DIRS} )
	add_executable( ${EXEC} main.cpp stdin-employee-factory.cpp ptree-employee-factory.cpp )
	install( TARGETS ${EXEC} RUNTIME DESTINATION ${BIN_INSTALL_LOCATION} )
	# Don't smoke test this program, because it asks for user input. 
	# That'll block the testing process.
    #------------------
    unset( EXEC )
	
endif()

#############################################################################
