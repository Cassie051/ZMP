# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kasia/Dokumenty/ZMP/etap1/zalazek

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug

# Include any dependencies generated for this target.
include plugin/CMakeFiles/Interp4Pause.dir/depend.make

# Include the progress variables for this target.
include plugin/CMakeFiles/Interp4Pause.dir/progress.make

# Include the compile flags for this target's objects.
include plugin/CMakeFiles/Interp4Pause.dir/flags.make

plugin/CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.o: plugin/CMakeFiles/Interp4Pause.dir/flags.make
plugin/CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.o: ../plugin/src/Interp4Pause.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugin/CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.o"
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.o -c /home/kasia/Dokumenty/ZMP/etap1/zalazek/plugin/src/Interp4Pause.cpp

plugin/CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.i"
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kasia/Dokumenty/ZMP/etap1/zalazek/plugin/src/Interp4Pause.cpp > CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.i

plugin/CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.s"
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kasia/Dokumenty/ZMP/etap1/zalazek/plugin/src/Interp4Pause.cpp -o CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.s

# Object files for target Interp4Pause
Interp4Pause_OBJECTS = \
"CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.o"

# External object files for target Interp4Pause
Interp4Pause_EXTERNAL_OBJECTS =

plugin/libInterp4Pause.so: plugin/CMakeFiles/Interp4Pause.dir/src/Interp4Pause.cpp.o
plugin/libInterp4Pause.so: plugin/CMakeFiles/Interp4Pause.dir/build.make
plugin/libInterp4Pause.so: plugin/CMakeFiles/Interp4Pause.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libInterp4Pause.so"
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Interp4Pause.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugin/CMakeFiles/Interp4Pause.dir/build: plugin/libInterp4Pause.so

.PHONY : plugin/CMakeFiles/Interp4Pause.dir/build

plugin/CMakeFiles/Interp4Pause.dir/clean:
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin && $(CMAKE_COMMAND) -P CMakeFiles/Interp4Pause.dir/cmake_clean.cmake
.PHONY : plugin/CMakeFiles/Interp4Pause.dir/clean

plugin/CMakeFiles/Interp4Pause.dir/depend:
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kasia/Dokumenty/ZMP/etap1/zalazek /home/kasia/Dokumenty/ZMP/etap1/zalazek/plugin /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/plugin/CMakeFiles/Interp4Pause.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugin/CMakeFiles/Interp4Pause.dir/depend

