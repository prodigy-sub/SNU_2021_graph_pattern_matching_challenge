# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.20.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.20.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build

# Include any dependencies generated for this target.
include main/CMakeFiles/program.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include main/CMakeFiles/program.dir/compiler_depend.make

# Include the progress variables for this target.
include main/CMakeFiles/program.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/program.dir/flags.make

main/CMakeFiles/program.dir/main.cc.o: main/CMakeFiles/program.dir/flags.make
main/CMakeFiles/program.dir/main.cc.o: ../main/main.cc
main/CMakeFiles/program.dir/main.cc.o: main/CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/program.dir/main.cc.o"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/program.dir/main.cc.o -MF CMakeFiles/program.dir/main.cc.o.d -o CMakeFiles/program.dir/main.cc.o -c /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/main/main.cc

main/CMakeFiles/program.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/main.cc.i"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/main/main.cc > CMakeFiles/program.dir/main.cc.i

main/CMakeFiles/program.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/main.cc.s"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/main/main.cc -o CMakeFiles/program.dir/main.cc.s

main/CMakeFiles/program.dir/__/src/backtrack.cc.o: main/CMakeFiles/program.dir/flags.make
main/CMakeFiles/program.dir/__/src/backtrack.cc.o: ../src/backtrack.cc
main/CMakeFiles/program.dir/__/src/backtrack.cc.o: main/CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object main/CMakeFiles/program.dir/__/src/backtrack.cc.o"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/program.dir/__/src/backtrack.cc.o -MF CMakeFiles/program.dir/__/src/backtrack.cc.o.d -o CMakeFiles/program.dir/__/src/backtrack.cc.o -c /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/backtrack.cc

main/CMakeFiles/program.dir/__/src/backtrack.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/__/src/backtrack.cc.i"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/backtrack.cc > CMakeFiles/program.dir/__/src/backtrack.cc.i

main/CMakeFiles/program.dir/__/src/backtrack.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/__/src/backtrack.cc.s"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/backtrack.cc -o CMakeFiles/program.dir/__/src/backtrack.cc.s

main/CMakeFiles/program.dir/__/src/candidate_set.cc.o: main/CMakeFiles/program.dir/flags.make
main/CMakeFiles/program.dir/__/src/candidate_set.cc.o: ../src/candidate_set.cc
main/CMakeFiles/program.dir/__/src/candidate_set.cc.o: main/CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object main/CMakeFiles/program.dir/__/src/candidate_set.cc.o"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/program.dir/__/src/candidate_set.cc.o -MF CMakeFiles/program.dir/__/src/candidate_set.cc.o.d -o CMakeFiles/program.dir/__/src/candidate_set.cc.o -c /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/candidate_set.cc

main/CMakeFiles/program.dir/__/src/candidate_set.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/__/src/candidate_set.cc.i"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/candidate_set.cc > CMakeFiles/program.dir/__/src/candidate_set.cc.i

main/CMakeFiles/program.dir/__/src/candidate_set.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/__/src/candidate_set.cc.s"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/candidate_set.cc -o CMakeFiles/program.dir/__/src/candidate_set.cc.s

main/CMakeFiles/program.dir/__/src/graph.cc.o: main/CMakeFiles/program.dir/flags.make
main/CMakeFiles/program.dir/__/src/graph.cc.o: ../src/graph.cc
main/CMakeFiles/program.dir/__/src/graph.cc.o: main/CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object main/CMakeFiles/program.dir/__/src/graph.cc.o"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/program.dir/__/src/graph.cc.o -MF CMakeFiles/program.dir/__/src/graph.cc.o.d -o CMakeFiles/program.dir/__/src/graph.cc.o -c /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/graph.cc

main/CMakeFiles/program.dir/__/src/graph.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/__/src/graph.cc.i"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/graph.cc > CMakeFiles/program.dir/__/src/graph.cc.i

main/CMakeFiles/program.dir/__/src/graph.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/__/src/graph.cc.s"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/src/graph.cc -o CMakeFiles/program.dir/__/src/graph.cc.s

# Object files for target program
program_OBJECTS = \
"CMakeFiles/program.dir/main.cc.o" \
"CMakeFiles/program.dir/__/src/backtrack.cc.o" \
"CMakeFiles/program.dir/__/src/candidate_set.cc.o" \
"CMakeFiles/program.dir/__/src/graph.cc.o"

# External object files for target program
program_EXTERNAL_OBJECTS =

main/program: main/CMakeFiles/program.dir/main.cc.o
main/program: main/CMakeFiles/program.dir/__/src/backtrack.cc.o
main/program: main/CMakeFiles/program.dir/__/src/candidate_set.cc.o
main/program: main/CMakeFiles/program.dir/__/src/graph.cc.o
main/program: main/CMakeFiles/program.dir/build.make
main/program: main/CMakeFiles/program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable program"
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/program.dir/build: main/program
.PHONY : main/CMakeFiles/program.dir/build

main/CMakeFiles/program.dir/clean:
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main && $(CMAKE_COMMAND) -P CMakeFiles/program.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/program.dir/clean

main/CMakeFiles/program.dir/depend:
	cd /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/main /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main /Users/dongsubshin/Desktop/2021-1/알고리즘/SNU_2021_graph_pattern_matching_challenge/build/main/CMakeFiles/program.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/program.dir/depend
