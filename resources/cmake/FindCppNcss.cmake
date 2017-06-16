# - try to find cppncss tool
#
# Cache Variables:
#  CPPNCSS_EXECUTABLE
#
# Non-cache variables you might use in your CMakeLists.txt:
#  CPPNCSS_FOUND
#
# Requires these CMake modules:
#  FindPackageHandleStandardArgs 
#

file( TO_CMAKE_PATH "${CPPNCSS_ROOT_DIR}" CPPNCSS_ROOT_DIR )
set( CPPNCSS_ROOT_DIR "${CPPNCSS_ROOT_DIR}" CACHE PATH "Path to search for cppncss" )

# If we have a custom path, look there first.
if( CPPNCSS_ROOT_DIR )
	find_program( CPPNCSS_EXECUTABLE NAME cppncss PATHS "${CPPNCSS_ROOT_DIR}" )
endif()

find_program( CPPNCSS_EXECUTABLE NAME cppncss PATHS /opt/cppncss/bin /usr/local/cppncss/bin )

include( FindPackageHandleStandardArgs )
find_package_handle_standard_args( cppncss DEFAULT_MSG CPPNCSS_EXECUTABLE )

if( CPPNCSS_FOUND OR CPPNCSS_MARK_AS_ADVANCED )
	mark_as_advanced(CPPNCSS_ROOT_DIR)
endif()

mark_as_advanced( CPPNCSS_EXECUTABLE )
