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
#	Macros related to build & install procedures. 
#
#############################################################################

#============================================================================
# User defined options:
#============================================================================
option( GOBELIJN_INCLUDE_DOC 
	"Exclude site directory from build and install."  OFF )
option( GOBELIJN_VERBOSE_TESTING  
	"Run tests in verbose mode."  OFF )

#============================================================================
# Install sub-directory definitions
#============================================================================
set( BIN_INSTALL_LOCATION	    bin     )
set( LIB_INSTALL_LOCATION	    lib     )
set( INCLUDE_INSTALL_LOCATION   include )
set( DATA_INSTALL_LOCATION	    data    )
set( DOC_INSTALL_LOCATION	    doc     )
set( TESTS_INSTALL_LOCATION	    tests   )

#############################################################################
