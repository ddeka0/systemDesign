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
CMAKE_COMMAND = /snap/cmake/870/bin/cmake

# The command to remove a file.
RM = /snap/cmake/870/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deka/Academic/systemDesign/movieRecommendation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deka/Academic/systemDesign/movieRecommendation

# Include any dependencies generated for this target.
include CMakeFiles/movieRecommend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/movieRecommend.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/movieRecommend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/movieRecommend.dir/flags.make

CMakeFiles/movieRecommend.dir/test/src/main.cpp.o: CMakeFiles/movieRecommend.dir/flags.make
CMakeFiles/movieRecommend.dir/test/src/main.cpp.o: test/src/main.cpp
CMakeFiles/movieRecommend.dir/test/src/main.cpp.o: CMakeFiles/movieRecommend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deka/Academic/systemDesign/movieRecommendation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/movieRecommend.dir/test/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/movieRecommend.dir/test/src/main.cpp.o -MF CMakeFiles/movieRecommend.dir/test/src/main.cpp.o.d -o CMakeFiles/movieRecommend.dir/test/src/main.cpp.o -c /home/deka/Academic/systemDesign/movieRecommendation/test/src/main.cpp

CMakeFiles/movieRecommend.dir/test/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/movieRecommend.dir/test/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deka/Academic/systemDesign/movieRecommendation/test/src/main.cpp > CMakeFiles/movieRecommend.dir/test/src/main.cpp.i

CMakeFiles/movieRecommend.dir/test/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/movieRecommend.dir/test/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deka/Academic/systemDesign/movieRecommendation/test/src/main.cpp -o CMakeFiles/movieRecommend.dir/test/src/main.cpp.s

# Object files for target movieRecommend
movieRecommend_OBJECTS = \
"CMakeFiles/movieRecommend.dir/test/src/main.cpp.o"

# External object files for target movieRecommend
movieRecommend_EXTERNAL_OBJECTS =

build/bin/movieRecommend: CMakeFiles/movieRecommend.dir/test/src/main.cpp.o
build/bin/movieRecommend: CMakeFiles/movieRecommend.dir/build.make
build/bin/movieRecommend: bin_apis/liblibAPI.a
build/bin/movieRecommend: bin_core/liblibCORE.a
build/bin/movieRecommend: bin_model/liblibMODEL.a
build/bin/movieRecommend: CMakeFiles/movieRecommend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deka/Academic/systemDesign/movieRecommendation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable build/bin/movieRecommend"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/movieRecommend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/movieRecommend.dir/build: build/bin/movieRecommend
.PHONY : CMakeFiles/movieRecommend.dir/build

CMakeFiles/movieRecommend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/movieRecommend.dir/cmake_clean.cmake
.PHONY : CMakeFiles/movieRecommend.dir/clean

CMakeFiles/movieRecommend.dir/depend:
	cd /home/deka/Academic/systemDesign/movieRecommendation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deka/Academic/systemDesign/movieRecommendation /home/deka/Academic/systemDesign/movieRecommendation /home/deka/Academic/systemDesign/movieRecommendation /home/deka/Academic/systemDesign/movieRecommendation /home/deka/Academic/systemDesign/movieRecommendation/CMakeFiles/movieRecommend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/movieRecommend.dir/depend

