#============================================================================
# Build & install :
#============================================================================
# Only build this example if the boost libraries have been found.
if( Boost_FOUND )

	set(SRC
		constant-factory.h
		employee.h
		factory.h
		ptree-employee-factory.cpp
		stdin-employee-factory.cpp
	)
	set(EXEC abstract-factory)
	add_executable(${EXEC} main.cpp ${SRC})
	install(TARGETS ${EXEC} RUNTIME DESTINATION ${BIN_INSTALL_LOCATION})
	
	# Don't smoke test this program, because it asks for user input. 
	# That'll block the testing process.
	unset(SRC)
    unset(EXEC)
	
endif()

#############################################################################
