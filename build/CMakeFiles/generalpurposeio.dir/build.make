# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
include CMakeFiles/generalpurposeio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generalpurposeio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generalpurposeio.dir/flags.make

CMakeFiles/generalpurposeio.dir/Program/main.cpp.o: CMakeFiles/generalpurposeio.dir/flags.make
CMakeFiles/generalpurposeio.dir/Program/main.cpp.o: ../Program/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/david/projects/GeneralPurposeIO/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/generalpurposeio.dir/Program/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/generalpurposeio.dir/Program/main.cpp.o -c /home/david/projects/GeneralPurposeIO/Program/main.cpp

CMakeFiles/generalpurposeio.dir/Program/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generalpurposeio.dir/Program/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/david/projects/GeneralPurposeIO/Program/main.cpp > CMakeFiles/generalpurposeio.dir/Program/main.cpp.i

CMakeFiles/generalpurposeio.dir/Program/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generalpurposeio.dir/Program/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/david/projects/GeneralPurposeIO/Program/main.cpp -o CMakeFiles/generalpurposeio.dir/Program/main.cpp.s

CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.requires:
.PHONY : CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.requires

CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.provides: CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/generalpurposeio.dir/build.make CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.provides.build
.PHONY : CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.provides

CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.provides.build: CMakeFiles/generalpurposeio.dir/Program/main.cpp.o

# Object files for target generalpurposeio
generalpurposeio_OBJECTS = \
"CMakeFiles/generalpurposeio.dir/Program/main.cpp.o"

# External object files for target generalpurposeio
generalpurposeio_EXTERNAL_OBJECTS =

generalpurposeio: CMakeFiles/generalpurposeio.dir/Program/main.cpp.o
generalpurposeio: CMakeFiles/generalpurposeio.dir/build.make
generalpurposeio: Common/libCommon.a
generalpurposeio: RaspberryPi2/libRaspberryPi2.a
generalpurposeio: Common/libCommon.a
generalpurposeio: CMakeFiles/generalpurposeio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable generalpurposeio"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generalpurposeio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generalpurposeio.dir/build: generalpurposeio
.PHONY : CMakeFiles/generalpurposeio.dir/build

CMakeFiles/generalpurposeio.dir/requires: CMakeFiles/generalpurposeio.dir/Program/main.cpp.o.requires
.PHONY : CMakeFiles/generalpurposeio.dir/requires

CMakeFiles/generalpurposeio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generalpurposeio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generalpurposeio.dir/clean

CMakeFiles/generalpurposeio.dir/depend:
	cd /home/david/projects/GeneralPurposeIO/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/projects/GeneralPurposeIO /home/david/projects/GeneralPurposeIO /home/david/projects/GeneralPurposeIO/build /home/david/projects/GeneralPurposeIO/build /home/david/projects/GeneralPurposeIO/build/CMakeFiles/generalpurposeio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generalpurposeio.dir/depend

