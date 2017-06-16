# - try to find sloccount tool
#
# Cache Variables:
#  SLOCCOUNT_EXECUTABLE
#
# Non-cache variables you might use in your CMakeLists.txt:
#  SLOCCOUNT_FOUND
#
# Requires these CMake modules:
#  FindPackageHandleStandardArgs 
#

file( TO_CMAKE_PATH "${SLOCCOUNT_ROOT_DIR}" SLOCCOUNT_ROOT_DIR )
set( SLOCCOUNT_ROOT_DIR "${SLOCCOUNT_ROOT_DIR}" CACHE PATH "Path to search for sloccount" )

# If we have a custom path, look there first.
if( SLOCCOUNT_ROOT_DIR )
	find_program( SLOCCOUNT_EXECUTABLE NAME sloccount PATHS "${SLOCCOUNT_ROOT_DIR}" )
endif()

find_program( SLOCCOUNT_EXECUTABLE NAME sloccount PATHS /opt/sloccount/bin /usr/local/sloccount/bin )

include( FindPackageHandleStandardArgs )
find_package_handle_standard_args( sloccount DEFAULT_MSG SLOCCOUNT_EXECUTABLE )

if( SLOCCOUNT_FOUND OR SLOCCOUNT_MARK_AS_ADVANCED )
	mark_as_advanced(SLOCCOUNT_ROOT_DIR)
endif()

mark_as_advanced( SLOCCOUNT_EXECUTABLE )
