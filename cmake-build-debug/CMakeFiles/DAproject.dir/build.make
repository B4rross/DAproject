# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/david/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/223.8617.54/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/david/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/223.8617.54/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/Desktop/DA/DAproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Desktop/DA/DAproject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DAproject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DAproject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DAproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DAproject.dir/flags.make

CMakeFiles/DAproject.dir/main.cpp.o: CMakeFiles/DAproject.dir/flags.make
CMakeFiles/DAproject.dir/main.cpp.o: /home/david/Desktop/DA/DAproject/main.cpp
CMakeFiles/DAproject.dir/main.cpp.o: CMakeFiles/DAproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DAproject.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAproject.dir/main.cpp.o -MF CMakeFiles/DAproject.dir/main.cpp.o.d -o CMakeFiles/DAproject.dir/main.cpp.o -c /home/david/Desktop/DA/DAproject/main.cpp

CMakeFiles/DAproject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAproject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/DA/DAproject/main.cpp > CMakeFiles/DAproject.dir/main.cpp.i

CMakeFiles/DAproject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAproject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/DA/DAproject/main.cpp -o CMakeFiles/DAproject.dir/main.cpp.s

CMakeFiles/DAproject.dir/Graph.cpp.o: CMakeFiles/DAproject.dir/flags.make
CMakeFiles/DAproject.dir/Graph.cpp.o: /home/david/Desktop/DA/DAproject/Graph.cpp
CMakeFiles/DAproject.dir/Graph.cpp.o: CMakeFiles/DAproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DAproject.dir/Graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAproject.dir/Graph.cpp.o -MF CMakeFiles/DAproject.dir/Graph.cpp.o.d -o CMakeFiles/DAproject.dir/Graph.cpp.o -c /home/david/Desktop/DA/DAproject/Graph.cpp

CMakeFiles/DAproject.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAproject.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/DA/DAproject/Graph.cpp > CMakeFiles/DAproject.dir/Graph.cpp.i

CMakeFiles/DAproject.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAproject.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/DA/DAproject/Graph.cpp -o CMakeFiles/DAproject.dir/Graph.cpp.s

CMakeFiles/DAproject.dir/VertexEdge.cpp.o: CMakeFiles/DAproject.dir/flags.make
CMakeFiles/DAproject.dir/VertexEdge.cpp.o: /home/david/Desktop/DA/DAproject/VertexEdge.cpp
CMakeFiles/DAproject.dir/VertexEdge.cpp.o: CMakeFiles/DAproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DAproject.dir/VertexEdge.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAproject.dir/VertexEdge.cpp.o -MF CMakeFiles/DAproject.dir/VertexEdge.cpp.o.d -o CMakeFiles/DAproject.dir/VertexEdge.cpp.o -c /home/david/Desktop/DA/DAproject/VertexEdge.cpp

CMakeFiles/DAproject.dir/VertexEdge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAproject.dir/VertexEdge.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/DA/DAproject/VertexEdge.cpp > CMakeFiles/DAproject.dir/VertexEdge.cpp.i

CMakeFiles/DAproject.dir/VertexEdge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAproject.dir/VertexEdge.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/DA/DAproject/VertexEdge.cpp -o CMakeFiles/DAproject.dir/VertexEdge.cpp.s

CMakeFiles/DAproject.dir/Station.cpp.o: CMakeFiles/DAproject.dir/flags.make
CMakeFiles/DAproject.dir/Station.cpp.o: /home/david/Desktop/DA/DAproject/Station.cpp
CMakeFiles/DAproject.dir/Station.cpp.o: CMakeFiles/DAproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DAproject.dir/Station.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAproject.dir/Station.cpp.o -MF CMakeFiles/DAproject.dir/Station.cpp.o.d -o CMakeFiles/DAproject.dir/Station.cpp.o -c /home/david/Desktop/DA/DAproject/Station.cpp

CMakeFiles/DAproject.dir/Station.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAproject.dir/Station.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/DA/DAproject/Station.cpp > CMakeFiles/DAproject.dir/Station.cpp.i

CMakeFiles/DAproject.dir/Station.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAproject.dir/Station.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/DA/DAproject/Station.cpp -o CMakeFiles/DAproject.dir/Station.cpp.s

CMakeFiles/DAproject.dir/CPheadquarters.cpp.o: CMakeFiles/DAproject.dir/flags.make
CMakeFiles/DAproject.dir/CPheadquarters.cpp.o: /home/david/Desktop/DA/DAproject/CPheadquarters.cpp
CMakeFiles/DAproject.dir/CPheadquarters.cpp.o: CMakeFiles/DAproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DAproject.dir/CPheadquarters.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DAproject.dir/CPheadquarters.cpp.o -MF CMakeFiles/DAproject.dir/CPheadquarters.cpp.o.d -o CMakeFiles/DAproject.dir/CPheadquarters.cpp.o -c /home/david/Desktop/DA/DAproject/CPheadquarters.cpp

CMakeFiles/DAproject.dir/CPheadquarters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAproject.dir/CPheadquarters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/DA/DAproject/CPheadquarters.cpp > CMakeFiles/DAproject.dir/CPheadquarters.cpp.i

CMakeFiles/DAproject.dir/CPheadquarters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAproject.dir/CPheadquarters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/DA/DAproject/CPheadquarters.cpp -o CMakeFiles/DAproject.dir/CPheadquarters.cpp.s

# Object files for target DAproject
DAproject_OBJECTS = \
"CMakeFiles/DAproject.dir/main.cpp.o" \
"CMakeFiles/DAproject.dir/Graph.cpp.o" \
"CMakeFiles/DAproject.dir/VertexEdge.cpp.o" \
"CMakeFiles/DAproject.dir/Station.cpp.o" \
"CMakeFiles/DAproject.dir/CPheadquarters.cpp.o"

# External object files for target DAproject
DAproject_EXTERNAL_OBJECTS =

DAproject: CMakeFiles/DAproject.dir/main.cpp.o
DAproject: CMakeFiles/DAproject.dir/Graph.cpp.o
DAproject: CMakeFiles/DAproject.dir/VertexEdge.cpp.o
DAproject: CMakeFiles/DAproject.dir/Station.cpp.o
DAproject: CMakeFiles/DAproject.dir/CPheadquarters.cpp.o
DAproject: CMakeFiles/DAproject.dir/build.make
DAproject: CMakeFiles/DAproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable DAproject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DAproject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DAproject.dir/build: DAproject
.PHONY : CMakeFiles/DAproject.dir/build

CMakeFiles/DAproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DAproject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DAproject.dir/clean

CMakeFiles/DAproject.dir/depend:
	cd /home/david/Desktop/DA/DAproject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Desktop/DA/DAproject /home/david/Desktop/DA/DAproject /home/david/Desktop/DA/DAproject/cmake-build-debug /home/david/Desktop/DA/DAproject/cmake-build-debug /home/david/Desktop/DA/DAproject/cmake-build-debug/CMakeFiles/DAproject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DAproject.dir/depend

