# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/projects/GeneralPurposeIO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/projects/GeneralPurposeIO/build

# Include any dependencies generated for this target.
include Common/CMakeFiles/Common.dir/depend.make

# Include the progress variables for this target.
include Common/CMakeFiles/Common.dir/progress.make

# Include the compile flags for this target's objects.
include Common/CMakeFiles/Common.dir/flags.make

Common/CMakeFiles/Common.dir/GPIO.cpp.o: Common/CMakeFiles/Common.dir/flags.make
Common/CMakeFiles/Common.dir/GPIO.cpp.o: ../Common/GPIO.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/david/projects/GeneralPurposeIO/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Common/CMakeFiles/Common.dir/GPIO.cpp.o"
	cd /home/david/projects/GeneralPurposeIO/build/Common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Common.dir/GPIO.cpp.o -c /home/david/projects/GeneralPurposeIO/Common/GPIO.cpp

Common/CMakeFiles/Common.dir/GPIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Common.dir/GPIO.cpp.i"
	cd /home/david/projects/GeneralPurposeIO/build/Common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/david/projects/GeneralPurposeIO/Common/GPIO.cpp > CMakeFiles/Common.dir/GPIO.cpp.i

Common/CMakeFiles/Common.dir/GPIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Common.dir/GPIO.cpp.s"
	cd /home/david/projects/GeneralPurposeIO/build/Common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/david/projects/GeneralPurposeIO/Common/GPIO.cpp -o CMakeFiles/Common.dir/GPIO.cpp.s

Common/CMakeFiles/Common.dir/GPIO.cpp.o.requires:
.PHONY : Common/CMakeFiles/Common.dir/GPIO.cpp.o.requires

Common/CMakeFiles/Common.dir/GPIO.cpp.o.provides: Common/CMakeFiles/Common.dir/GPIO.cpp.o.requires
	$(MAKE) -f Common/CMakeFiles/Common.dir/build.make Common/CMakeFiles/Common.dir/GPIO.cpp.o.provides.build
.PHONY : Common/CMakeFiles/Common.dir/GPIO.cpp.o.provides

Common/CMakeFiles/Common.dir/GPIO.cpp.o.provides.build: Common/CMakeFiles/Common.dir/GPIO.cpp.o

# Object files for target Common
Common_OBJECTS = \
"CMakeFiles/Common.dir/GPIO.cpp.o"

# External object files for target Common
Common_EXTERNAL_OBJECTS =

Common/libCommon.a: Common/CMakeFiles/Common.dir/GPIO.cpp.o
Common/libCommon.a: Common/CMakeFiles/Common.dir/build.make
Common/libCommon.a: Common/CMakeFiles/Common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libCommon.a"
	cd /home/david/projects/GeneralPurposeIO/build/Common && $(CMAKE_COMMAND) -P CMakeFiles/Common.dir/cmake_clean_target.cmake
	cd /home/david/projects/GeneralPurposeIO/build/Common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Common/CMakeFiles/Common.dir/build: Common/libCommon.a
.PHONY : Common/CMakeFiles/Common.dir/build

Common/CMakeFiles/Common.dir/requires: Common/CMakeFiles/Common.dir/GPIO.cpp.o.requires
.PHONY : Common/CMakeFiles/Common.dir/requires

Common/CMakeFiles/Common.dir/clean:
	cd /home/david/projects/GeneralPurposeIO/build/Common && $(CMAKE_COMMAND) -P CMakeFiles/Common.dir/cmake_clean.cmake
.PHONY : Common/CMakeFiles/Common.dir/clean

Common/CMakeFiles/Common.dir/depend:
	cd /home/david/projects/GeneralPurposeIO/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/projects/GeneralPurposeIO /home/david/projects/GeneralPurposeIO/Common /home/david/projects/GeneralPurposeIO/build /home/david/projects/GeneralPurposeIO/build/Common /home/david/projects/GeneralPurposeIO/build/Common/CMakeFiles/Common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Common/CMakeFiles/Common.dir/depend
