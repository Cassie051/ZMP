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
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/Dokumenty/ZMP/etap2/zalazek

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug

# Include any dependencies generated for this target.
include plugin/CMakeFiles/Interp4Set.dir/depend.make

# Include the progress variables for this target.
include plugin/CMakeFiles/Interp4Set.dir/progress.make

# Include the compile flags for this target's objects.
include plugin/CMakeFiles/Interp4Set.dir/flags.make

plugin/CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.o: plugin/CMakeFiles/Interp4Set.dir/flags.make
plugin/CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.o: ../plugin/src/Interp4Set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugin/CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.o"
	cd /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.o -c /home/nick/Dokumenty/ZMP/etap2/zalazek/plugin/src/Interp4Set.cpp

plugin/CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.i"
	cd /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/Dokumenty/ZMP/etap2/zalazek/plugin/src/Interp4Set.cpp > CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.i

plugin/CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.s"
	cd /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/Dokumenty/ZMP/etap2/zalazek/plugin/src/Interp4Set.cpp -o CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.s

# Object files for target Interp4Set
Interp4Set_OBJECTS = \
"CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.o"

# External object files for target Interp4Set
Interp4Set_EXTERNAL_OBJECTS =

plugin/libInterp4Set.so: plugin/CMakeFiles/Interp4Set.dir/src/Interp4Set.cpp.o
plugin/libInterp4Set.so: plugin/CMakeFiles/Interp4Set.dir/build.make
plugin/libInterp4Set.so: plugin/CMakeFiles/Interp4Set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libInterp4Set.so"
	cd /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Interp4Set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugin/CMakeFiles/Interp4Set.dir/build: plugin/libInterp4Set.so

.PHONY : plugin/CMakeFiles/Interp4Set.dir/build

plugin/CMakeFiles/Interp4Set.dir/clean:
	cd /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin && $(CMAKE_COMMAND) -P CMakeFiles/Interp4Set.dir/cmake_clean.cmake
.PHONY : plugin/CMakeFiles/Interp4Set.dir/clean

plugin/CMakeFiles/Interp4Set.dir/depend:
	cd /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/Dokumenty/ZMP/etap2/zalazek /home/nick/Dokumenty/ZMP/etap2/zalazek/plugin /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin /home/nick/Dokumenty/ZMP/etap2/zalazek/cmake-build-debug/plugin/CMakeFiles/Interp4Set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugin/CMakeFiles/Interp4Set.dir/depend

