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
include CMakeFiles/interpreter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interpreter.dir/flags.make

CMakeFiles/interpreter.dir/src/main.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interpreter.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/src/main.cpp.o -c /home/kasia/Dokumenty/ZMP/etap1/zalazek/src/main.cpp

CMakeFiles/interpreter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kasia/Dokumenty/ZMP/etap1/zalazek/src/main.cpp > CMakeFiles/interpreter.dir/src/main.cpp.i

CMakeFiles/interpreter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kasia/Dokumenty/ZMP/etap1/zalazek/src/main.cpp -o CMakeFiles/interpreter.dir/src/main.cpp.s

# Object files for target interpreter
interpreter_OBJECTS = \
"CMakeFiles/interpreter.dir/src/main.cpp.o"

# External object files for target interpreter
interpreter_EXTERNAL_OBJECTS =

interpreter: CMakeFiles/interpreter.dir/src/main.cpp.o
interpreter: CMakeFiles/interpreter.dir/build.make
interpreter: plugin/libInterp4Move.so
interpreter: plugin/libInterp4Set.so
interpreter: plugin/libInterp4Pause.so
interpreter: CMakeFiles/interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable interpreter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interpreter.dir/build: interpreter

.PHONY : CMakeFiles/interpreter.dir/build

CMakeFiles/interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interpreter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interpreter.dir/clean

CMakeFiles/interpreter.dir/depend:
	cd /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kasia/Dokumenty/ZMP/etap1/zalazek /home/kasia/Dokumenty/ZMP/etap1/zalazek /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug /home/kasia/Dokumenty/ZMP/etap1/zalazek/cmake-build-debug/CMakeFiles/interpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interpreter.dir/depend

