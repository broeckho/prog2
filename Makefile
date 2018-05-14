#############################################################################
#  This file is part of the software project.
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
#  Copyright 2017, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################
#
#	Meta makefile calls cmake to do the heavy lifting.
#
#############################################################################

#============================================================================
#   Configuring Make invocations.
#============================================================================
NCORES=`getconf _NPROCESSORS_ONLN`
ifeq ($(PARALLEL_MAKE),)
	PARALLEL_MAKE = -j$(NCORES)
endif

#============================================================================
# 	CMake command for Mac OSX or *nix
#============================================================================
ifeq ($(CMAKE),)
	CMAKE = cmake
endif

#============================================================================
#   Test related: had to duplicate CMAKE_INSTALL_PREFIX here for gtester
#============================================================================
LABEL=$(shell git rev-list HEAD --count)
CMAKE_INSTALL_PREFIX  = $(HOME)/opt/stride-$(LABEL)

#============================================================================
#   MACRO definitions to pass on to cmake
#============================================================================
CMAKE_ARGS += -DCMAKE_GENERATOR="Unix Makefiles"
#
ifneq ($(CMAKE_INSTALL_PREFIX),)
	CMAKE_ARGS += -DCMAKE_INSTALL_PREFIX:PATH=$(CMAKE_INSTALL_PREFIX)
endif
ifneq ($(GOBELIJN_INCLUDE_DOC),)
	CMAKE_ARGS += -DGOBELIJN_INCLUDE_DOC:BOOL=$(GOBELIJN_INCLUDE_DOC)
endif

#============================================================================
#   Build directory.
#============================================================================
ifeq ($(BUILD_DIR),)
ifeq ($(CMAKE_BUILD_TYPE),Debug)
	BUILD_DIR = ./cmake-build-debug
else
	BUILD_DIR = ./cmake-build-release
endif
endif

#============================================================================
#   Targets
#============================================================================
.PHONY: cores configure all install clean distclean test gtest format

help:
	@ $(CMAKE) -E echo " "
	@ $(CMAKE) -E echo " Read INSTALL.txt in this directory for a brief overview."
	@ $(CMAKE) -E echo " Current macro values are:"
	@ $(CMAKE) -E echo " "
	@ $(CMAKE) -E echo "   BUILD_DIR                      : " $(BUILD_DIR)
	@ $(CMAKE) -E echo " "
	@ $(CMAKE) -E echo "   CMAKE_GENERATOR                : " $(CMAKE_GENERATOR)
	@ $(CMAKE) -E echo "   CMAKE_BUILD_TYPE               : " $(CMAKE_BUILD_TYPE)
	@ $(CMAKE) -E echo "   CMAKE_INSTALL_PREFIX           : " $(CMAKE_INSTALL_PREFIX)
	@ $(CMAKE) -E echo " "
	@ $(CMAKE) -E echo "   GOBELIJN_INCLUDE_DOC           : " $(GOBELIJN_INCLUDE_DOC)
	@ $(CMAKE) -E echo " "

cores:
	@ echo "\nMake invocation using -j"$(NCORES) "\n"

configure: cores
	$(CMAKE) -E make_directory $(BUILD_DIR)
	$(CMAKE) -E chdir $(BUILD_DIR) $(CMAKE) $(CMAKE_ARGS) ..

all: configure
	$(MAKE) $(PARALLEL_MAKE) -C $(BUILD_DIR) --no-print-directory all

install: cores
	$(MAKE) $(PARALLEL_MAKE) -C $(BUILD_DIR) --no-print-directory install   

clean: cores
	 if [ -d $(BUILD_DIR) ]; then $(MAKE) $(PARALLEL_MAKE) -C $(BUILD_DIR) clean; fi

distclean:
	$(CMAKE) -E remove_directory $(BUILD_DIR)

test: install
	cd $(BUILD_DIR)/test; ctest $(TESTARGS) -V

gtest: install
	cd $(CMAKE_INSTALL_PREFIX); bin/gtester $(TESTARGS)

format:
	resources/bash/clang-format-all .
	resources/bash/remove_trailing_space
	
#############################################################################
