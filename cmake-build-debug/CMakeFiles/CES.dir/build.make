# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jsantillana/University/compiladores/CES-Compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CES.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CES.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CES.dir/flags.make

CMakeFiles/CES.dir/main.cpp.o: CMakeFiles/CES.dir/flags.make
CMakeFiles/CES.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CES.dir/main.cpp.o"
	/usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CES.dir/main.cpp.o -c /Users/jsantillana/University/compiladores/CES-Compiler/main.cpp

CMakeFiles/CES.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CES.dir/main.cpp.i"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jsantillana/University/compiladores/CES-Compiler/main.cpp > CMakeFiles/CES.dir/main.cpp.i

CMakeFiles/CES.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CES.dir/main.cpp.s"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jsantillana/University/compiladores/CES-Compiler/main.cpp -o CMakeFiles/CES.dir/main.cpp.s

CMakeFiles/CES.dir/File.cpp.o: CMakeFiles/CES.dir/flags.make
CMakeFiles/CES.dir/File.cpp.o: ../File.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CES.dir/File.cpp.o"
	/usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CES.dir/File.cpp.o -c /Users/jsantillana/University/compiladores/CES-Compiler/File.cpp

CMakeFiles/CES.dir/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CES.dir/File.cpp.i"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jsantillana/University/compiladores/CES-Compiler/File.cpp > CMakeFiles/CES.dir/File.cpp.i

CMakeFiles/CES.dir/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CES.dir/File.cpp.s"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jsantillana/University/compiladores/CES-Compiler/File.cpp -o CMakeFiles/CES.dir/File.cpp.s

CMakeFiles/CES.dir/LexicalAnalyzer.cpp.o: CMakeFiles/CES.dir/flags.make
CMakeFiles/CES.dir/LexicalAnalyzer.cpp.o: ../LexicalAnalyzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CES.dir/LexicalAnalyzer.cpp.o"
	/usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CES.dir/LexicalAnalyzer.cpp.o -c /Users/jsantillana/University/compiladores/CES-Compiler/LexicalAnalyzer.cpp

CMakeFiles/CES.dir/LexicalAnalyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CES.dir/LexicalAnalyzer.cpp.i"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jsantillana/University/compiladores/CES-Compiler/LexicalAnalyzer.cpp > CMakeFiles/CES.dir/LexicalAnalyzer.cpp.i

CMakeFiles/CES.dir/LexicalAnalyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CES.dir/LexicalAnalyzer.cpp.s"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jsantillana/University/compiladores/CES-Compiler/LexicalAnalyzer.cpp -o CMakeFiles/CES.dir/LexicalAnalyzer.cpp.s

CMakeFiles/CES.dir/SymTable.cpp.o: CMakeFiles/CES.dir/flags.make
CMakeFiles/CES.dir/SymTable.cpp.o: ../SymTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CES.dir/SymTable.cpp.o"
	/usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CES.dir/SymTable.cpp.o -c /Users/jsantillana/University/compiladores/CES-Compiler/SymTable.cpp

CMakeFiles/CES.dir/SymTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CES.dir/SymTable.cpp.i"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jsantillana/University/compiladores/CES-Compiler/SymTable.cpp > CMakeFiles/CES.dir/SymTable.cpp.i

CMakeFiles/CES.dir/SymTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CES.dir/SymTable.cpp.s"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jsantillana/University/compiladores/CES-Compiler/SymTable.cpp -o CMakeFiles/CES.dir/SymTable.cpp.s

# Object files for target CES
CES_OBJECTS = \
"CMakeFiles/CES.dir/main.cpp.o" \
"CMakeFiles/CES.dir/File.cpp.o" \
"CMakeFiles/CES.dir/LexicalAnalyzer.cpp.o" \
"CMakeFiles/CES.dir/SymTable.cpp.o"

# External object files for target CES
CES_EXTERNAL_OBJECTS =

CES: CMakeFiles/CES.dir/main.cpp.o
CES: CMakeFiles/CES.dir/File.cpp.o
CES: CMakeFiles/CES.dir/LexicalAnalyzer.cpp.o
CES: CMakeFiles/CES.dir/SymTable.cpp.o
CES: CMakeFiles/CES.dir/build.make
CES: /usr/local/lib/libboost_system-mt.dylib
CES: /usr/local/lib/libboost_filesystem-mt.dylib
CES: CMakeFiles/CES.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable CES"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CES.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CES.dir/build: CES

.PHONY : CMakeFiles/CES.dir/build

CMakeFiles/CES.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CES.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CES.dir/clean

CMakeFiles/CES.dir/depend:
	cd /Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jsantillana/University/compiladores/CES-Compiler /Users/jsantillana/University/compiladores/CES-Compiler /Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug /Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug /Users/jsantillana/University/compiladores/CES-Compiler/cmake-build-debug/CMakeFiles/CES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CES.dir/depend

