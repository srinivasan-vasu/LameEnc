# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /snap/cmake/619/bin/cmake

# The command to remove a file.
RM = /snap/cmake/619/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/srnvsn/Documents/Projects/Lame/lameenc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/srnvsn/Documents/Projects/Lame/lameenc/build

# Include any dependencies generated for this target.
include CMakeFiles/lameenc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lameenc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lameenc.dir/flags.make

CMakeFiles/lameenc.dir/src/main.cpp.o: CMakeFiles/lameenc.dir/flags.make
CMakeFiles/lameenc.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/srnvsn/Documents/Projects/Lame/lameenc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lameenc.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lameenc.dir/src/main.cpp.o -c /home/srnvsn/Documents/Projects/Lame/lameenc/src/main.cpp

CMakeFiles/lameenc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lameenc.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/srnvsn/Documents/Projects/Lame/lameenc/src/main.cpp > CMakeFiles/lameenc.dir/src/main.cpp.i

CMakeFiles/lameenc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lameenc.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/srnvsn/Documents/Projects/Lame/lameenc/src/main.cpp -o CMakeFiles/lameenc.dir/src/main.cpp.s

CMakeFiles/lameenc.dir/src/lameWrapper.cpp.o: CMakeFiles/lameenc.dir/flags.make
CMakeFiles/lameenc.dir/src/lameWrapper.cpp.o: ../src/lameWrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/srnvsn/Documents/Projects/Lame/lameenc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lameenc.dir/src/lameWrapper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lameenc.dir/src/lameWrapper.cpp.o -c /home/srnvsn/Documents/Projects/Lame/lameenc/src/lameWrapper.cpp

CMakeFiles/lameenc.dir/src/lameWrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lameenc.dir/src/lameWrapper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/srnvsn/Documents/Projects/Lame/lameenc/src/lameWrapper.cpp > CMakeFiles/lameenc.dir/src/lameWrapper.cpp.i

CMakeFiles/lameenc.dir/src/lameWrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lameenc.dir/src/lameWrapper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/srnvsn/Documents/Projects/Lame/lameenc/src/lameWrapper.cpp -o CMakeFiles/lameenc.dir/src/lameWrapper.cpp.s

CMakeFiles/lameenc.dir/src/threadpool.cpp.o: CMakeFiles/lameenc.dir/flags.make
CMakeFiles/lameenc.dir/src/threadpool.cpp.o: ../src/threadpool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/srnvsn/Documents/Projects/Lame/lameenc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lameenc.dir/src/threadpool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lameenc.dir/src/threadpool.cpp.o -c /home/srnvsn/Documents/Projects/Lame/lameenc/src/threadpool.cpp

CMakeFiles/lameenc.dir/src/threadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lameenc.dir/src/threadpool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/srnvsn/Documents/Projects/Lame/lameenc/src/threadpool.cpp > CMakeFiles/lameenc.dir/src/threadpool.cpp.i

CMakeFiles/lameenc.dir/src/threadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lameenc.dir/src/threadpool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/srnvsn/Documents/Projects/Lame/lameenc/src/threadpool.cpp -o CMakeFiles/lameenc.dir/src/threadpool.cpp.s

# Object files for target lameenc
lameenc_OBJECTS = \
"CMakeFiles/lameenc.dir/src/main.cpp.o" \
"CMakeFiles/lameenc.dir/src/lameWrapper.cpp.o" \
"CMakeFiles/lameenc.dir/src/threadpool.cpp.o"

# External object files for target lameenc
lameenc_EXTERNAL_OBJECTS =

lameenc: CMakeFiles/lameenc.dir/src/main.cpp.o
lameenc: CMakeFiles/lameenc.dir/src/lameWrapper.cpp.o
lameenc: CMakeFiles/lameenc.dir/src/threadpool.cpp.o
lameenc: CMakeFiles/lameenc.dir/build.make
lameenc: CMakeFiles/lameenc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/srnvsn/Documents/Projects/Lame/lameenc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lameenc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lameenc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lameenc.dir/build: lameenc

.PHONY : CMakeFiles/lameenc.dir/build

CMakeFiles/lameenc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lameenc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lameenc.dir/clean

CMakeFiles/lameenc.dir/depend:
	cd /home/srnvsn/Documents/Projects/Lame/lameenc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/srnvsn/Documents/Projects/Lame/lameenc /home/srnvsn/Documents/Projects/Lame/lameenc /home/srnvsn/Documents/Projects/Lame/lameenc/build /home/srnvsn/Documents/Projects/Lame/lameenc/build /home/srnvsn/Documents/Projects/Lame/lameenc/build/CMakeFiles/lameenc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lameenc.dir/depend

