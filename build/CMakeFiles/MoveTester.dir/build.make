# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/giese405/Checkers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/giese405/Checkers/build

# Include any dependencies generated for this target.
include CMakeFiles/MoveTester.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MoveTester.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MoveTester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MoveTester.dir/flags.make

CMakeFiles/MoveTester.dir/MoveTester.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/MoveTester.cpp.o: /home/giese405/Checkers/MoveTester.cpp
CMakeFiles/MoveTester.dir/MoveTester.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MoveTester.dir/MoveTester.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/MoveTester.cpp.o -MF CMakeFiles/MoveTester.dir/MoveTester.cpp.o.d -o CMakeFiles/MoveTester.dir/MoveTester.cpp.o -c /home/giese405/Checkers/MoveTester.cpp

CMakeFiles/MoveTester.dir/MoveTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/MoveTester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/MoveTester.cpp > CMakeFiles/MoveTester.dir/MoveTester.cpp.i

CMakeFiles/MoveTester.dir/MoveTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/MoveTester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/MoveTester.cpp -o CMakeFiles/MoveTester.dir/MoveTester.cpp.s

CMakeFiles/MoveTester.dir/Board.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/Board.cpp.o: /home/giese405/Checkers/Board.cpp
CMakeFiles/MoveTester.dir/Board.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MoveTester.dir/Board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/Board.cpp.o -MF CMakeFiles/MoveTester.dir/Board.cpp.o.d -o CMakeFiles/MoveTester.dir/Board.cpp.o -c /home/giese405/Checkers/Board.cpp

CMakeFiles/MoveTester.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/Board.cpp > CMakeFiles/MoveTester.dir/Board.cpp.i

CMakeFiles/MoveTester.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/Board.cpp -o CMakeFiles/MoveTester.dir/Board.cpp.s

CMakeFiles/MoveTester.dir/JumpTree.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/JumpTree.cpp.o: /home/giese405/Checkers/JumpTree.cpp
CMakeFiles/MoveTester.dir/JumpTree.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MoveTester.dir/JumpTree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/JumpTree.cpp.o -MF CMakeFiles/MoveTester.dir/JumpTree.cpp.o.d -o CMakeFiles/MoveTester.dir/JumpTree.cpp.o -c /home/giese405/Checkers/JumpTree.cpp

CMakeFiles/MoveTester.dir/JumpTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/JumpTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/JumpTree.cpp > CMakeFiles/MoveTester.dir/JumpTree.cpp.i

CMakeFiles/MoveTester.dir/JumpTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/JumpTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/JumpTree.cpp -o CMakeFiles/MoveTester.dir/JumpTree.cpp.s

CMakeFiles/MoveTester.dir/Move.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/Move.cpp.o: /home/giese405/Checkers/Move.cpp
CMakeFiles/MoveTester.dir/Move.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MoveTester.dir/Move.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/Move.cpp.o -MF CMakeFiles/MoveTester.dir/Move.cpp.o.d -o CMakeFiles/MoveTester.dir/Move.cpp.o -c /home/giese405/Checkers/Move.cpp

CMakeFiles/MoveTester.dir/Move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/Move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/Move.cpp > CMakeFiles/MoveTester.dir/Move.cpp.i

CMakeFiles/MoveTester.dir/Move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/Move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/Move.cpp -o CMakeFiles/MoveTester.dir/Move.cpp.s

CMakeFiles/MoveTester.dir/Scores.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/Scores.cpp.o: /home/giese405/Checkers/Scores.cpp
CMakeFiles/MoveTester.dir/Scores.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MoveTester.dir/Scores.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/Scores.cpp.o -MF CMakeFiles/MoveTester.dir/Scores.cpp.o.d -o CMakeFiles/MoveTester.dir/Scores.cpp.o -c /home/giese405/Checkers/Scores.cpp

CMakeFiles/MoveTester.dir/Scores.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/Scores.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/Scores.cpp > CMakeFiles/MoveTester.dir/Scores.cpp.i

CMakeFiles/MoveTester.dir/Scores.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/Scores.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/Scores.cpp -o CMakeFiles/MoveTester.dir/Scores.cpp.s

CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o: /home/giese405/Checkers/CheckerBoard.cpp
CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o -MF CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o.d -o CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o -c /home/giese405/Checkers/CheckerBoard.cpp

CMakeFiles/MoveTester.dir/CheckerBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/CheckerBoard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/CheckerBoard.cpp > CMakeFiles/MoveTester.dir/CheckerBoard.cpp.i

CMakeFiles/MoveTester.dir/CheckerBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/CheckerBoard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/CheckerBoard.cpp -o CMakeFiles/MoveTester.dir/CheckerBoard.cpp.s

CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o: /home/giese405/Checkers/CheckerLogic.cpp
CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o -MF CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o.d -o CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o -c /home/giese405/Checkers/CheckerLogic.cpp

CMakeFiles/MoveTester.dir/CheckerLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/CheckerLogic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/CheckerLogic.cpp > CMakeFiles/MoveTester.dir/CheckerLogic.cpp.i

CMakeFiles/MoveTester.dir/CheckerLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/CheckerLogic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/CheckerLogic.cpp -o CMakeFiles/MoveTester.dir/CheckerLogic.cpp.s

CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o: /home/giese405/Checkers/CheckerMoveMaps.cpp
CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o -MF CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o.d -o CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o -c /home/giese405/Checkers/CheckerMoveMaps.cpp

CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/CheckerMoveMaps.cpp > CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.i

CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/CheckerMoveMaps.cpp -o CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.s

CMakeFiles/MoveTester.dir/JumpNode.cpp.o: CMakeFiles/MoveTester.dir/flags.make
CMakeFiles/MoveTester.dir/JumpNode.cpp.o: /home/giese405/Checkers/JumpNode.cpp
CMakeFiles/MoveTester.dir/JumpNode.cpp.o: CMakeFiles/MoveTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/MoveTester.dir/JumpNode.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MoveTester.dir/JumpNode.cpp.o -MF CMakeFiles/MoveTester.dir/JumpNode.cpp.o.d -o CMakeFiles/MoveTester.dir/JumpNode.cpp.o -c /home/giese405/Checkers/JumpNode.cpp

CMakeFiles/MoveTester.dir/JumpNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoveTester.dir/JumpNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giese405/Checkers/JumpNode.cpp > CMakeFiles/MoveTester.dir/JumpNode.cpp.i

CMakeFiles/MoveTester.dir/JumpNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoveTester.dir/JumpNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giese405/Checkers/JumpNode.cpp -o CMakeFiles/MoveTester.dir/JumpNode.cpp.s

# Object files for target MoveTester
MoveTester_OBJECTS = \
"CMakeFiles/MoveTester.dir/MoveTester.cpp.o" \
"CMakeFiles/MoveTester.dir/Board.cpp.o" \
"CMakeFiles/MoveTester.dir/JumpTree.cpp.o" \
"CMakeFiles/MoveTester.dir/Move.cpp.o" \
"CMakeFiles/MoveTester.dir/Scores.cpp.o" \
"CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o" \
"CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o" \
"CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o" \
"CMakeFiles/MoveTester.dir/JumpNode.cpp.o"

# External object files for target MoveTester
MoveTester_EXTERNAL_OBJECTS =

MoveTester: CMakeFiles/MoveTester.dir/MoveTester.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/Board.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/JumpTree.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/Move.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/Scores.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/CheckerBoard.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/CheckerLogic.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/CheckerMoveMaps.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/JumpNode.cpp.o
MoveTester: CMakeFiles/MoveTester.dir/build.make
MoveTester: CMakeFiles/MoveTester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/giese405/Checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable MoveTester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MoveTester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MoveTester.dir/build: MoveTester
.PHONY : CMakeFiles/MoveTester.dir/build

CMakeFiles/MoveTester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MoveTester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MoveTester.dir/clean

CMakeFiles/MoveTester.dir/depend:
	cd /home/giese405/Checkers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/giese405/Checkers /home/giese405/Checkers /home/giese405/Checkers/build /home/giese405/Checkers/build /home/giese405/Checkers/build/CMakeFiles/MoveTester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MoveTester.dir/depend

