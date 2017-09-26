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
#  Copyright 2012-2017, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################

#============================================================================
# api_doc
#============================================================================
find_package(Doxygen)

if(DOXYGEN_FOUND)

	#=== dot tool ===
	if( DOXYGEN_DOT_FOUND )
		set(DOXY_HAVE_DOT YES)
	else()
		set(DOXY_HAVE_DOT NO)
	endif()
    
	#=== setup ===          
	set(DOXY_HTML_DIR  ${CMAKE_BINARY_DIR}/docs/reference_doc_html)
	file(MAKE_DIRECTORY ${DOXY_HTML_DIR})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/GobelijnLogo.png DESTINATION ${DOXY_HTML_DIR})
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mainpage.doxy.in    ${CMAKE_CURRENT_BINARY_DIR}/mainpage.doxy)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/namespaces.doxy.in  ${CMAKE_CURRENT_BINARY_DIR}/namespaces.doxy)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.cmake.in   ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    
	#=== target ===
	add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} Doxyfile)

    #=== install ===
	# need to install image files though
	install(DIRECTORY ${DOXY_HTML_DIR} DESTINATION ${DOC_INSTALL_LOCATION})
	install(FILES reference_doc.html DESTINATION ${DOC_INSTALL_LOCATION})
	
	#=== unset ===
	unset( DOXY_HAVE_DOT )
   	unset( DOXY_HTML_DIR )
    
endif(DOXYGEN_FOUND)

#############################################################################