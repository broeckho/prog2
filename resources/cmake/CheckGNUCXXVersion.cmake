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
#	Check version if CXX compiler is GCC. Defines the variables:
# 
#	GNU_CXX_VERSION	 	version number with at least major and minor
#	GNU_CXX_VERSION_IS_OK   version exceeds pre-set minimum requirement
#
#############################################################################

#============================================================================
# CheckGNUCXXVersion
#============================================================================
function( CheckGNUCXXVersion GNU_CXX_VERSION GNU_CXX_VERSION_IS_OK )
	

message( STATUS "------> gcc cxx compiler version   : ${GNU_CXX_VERSION}"      )
		
endfunction( CheckGNUCXXVersion GNU_CXX_VERSION GNU_CXX_VERSION_IS_OK )

#############################################################################