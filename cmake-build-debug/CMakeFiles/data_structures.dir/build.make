# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/regoeco/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/163.7743.47/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/regoeco/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/163.7743.47/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/regoeco/Documentos/projects/data-structures-in-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/data_structures.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data_structures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_structures.dir/flags.make

CMakeFiles/data_structures.dir/stack/main.c.o: CMakeFiles/data_structures.dir/flags.make
CMakeFiles/data_structures.dir/stack/main.c.o: ../stack/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/data_structures.dir/stack/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structures.dir/stack/main.c.o   -c /home/regoeco/Documentos/projects/data-structures-in-C/stack/main.c

CMakeFiles/data_structures.dir/stack/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/stack/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/regoeco/Documentos/projects/data-structures-in-C/stack/main.c > CMakeFiles/data_structures.dir/stack/main.c.i

CMakeFiles/data_structures.dir/stack/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/stack/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/regoeco/Documentos/projects/data-structures-in-C/stack/main.c -o CMakeFiles/data_structures.dir/stack/main.c.s

CMakeFiles/data_structures.dir/stack/main.c.o.requires:

.PHONY : CMakeFiles/data_structures.dir/stack/main.c.o.requires

CMakeFiles/data_structures.dir/stack/main.c.o.provides: CMakeFiles/data_structures.dir/stack/main.c.o.requires
	$(MAKE) -f CMakeFiles/data_structures.dir/build.make CMakeFiles/data_structures.dir/stack/main.c.o.provides.build
.PHONY : CMakeFiles/data_structures.dir/stack/main.c.o.provides

CMakeFiles/data_structures.dir/stack/main.c.o.provides.build: CMakeFiles/data_structures.dir/stack/main.c.o


CMakeFiles/data_structures.dir/stack/stack.c.o: CMakeFiles/data_structures.dir/flags.make
CMakeFiles/data_structures.dir/stack/stack.c.o: ../stack/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/data_structures.dir/stack/stack.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structures.dir/stack/stack.c.o   -c /home/regoeco/Documentos/projects/data-structures-in-C/stack/stack.c

CMakeFiles/data_structures.dir/stack/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/stack/stack.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/regoeco/Documentos/projects/data-structures-in-C/stack/stack.c > CMakeFiles/data_structures.dir/stack/stack.c.i

CMakeFiles/data_structures.dir/stack/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/stack/stack.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/regoeco/Documentos/projects/data-structures-in-C/stack/stack.c -o CMakeFiles/data_structures.dir/stack/stack.c.s

CMakeFiles/data_structures.dir/stack/stack.c.o.requires:

.PHONY : CMakeFiles/data_structures.dir/stack/stack.c.o.requires

CMakeFiles/data_structures.dir/stack/stack.c.o.provides: CMakeFiles/data_structures.dir/stack/stack.c.o.requires
	$(MAKE) -f CMakeFiles/data_structures.dir/build.make CMakeFiles/data_structures.dir/stack/stack.c.o.provides.build
.PHONY : CMakeFiles/data_structures.dir/stack/stack.c.o.provides

CMakeFiles/data_structures.dir/stack/stack.c.o.provides.build: CMakeFiles/data_structures.dir/stack/stack.c.o


# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles/data_structures.dir/stack/main.c.o" \
"CMakeFiles/data_structures.dir/stack/stack.c.o"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

data_structures: CMakeFiles/data_structures.dir/stack/main.c.o
data_structures: CMakeFiles/data_structures.dir/stack/stack.c.o
data_structures: CMakeFiles/data_structures.dir/build.make
data_structures: CMakeFiles/data_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable data_structures"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_structures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_structures.dir/build: data_structures

.PHONY : CMakeFiles/data_structures.dir/build

CMakeFiles/data_structures.dir/requires: CMakeFiles/data_structures.dir/stack/main.c.o.requires
CMakeFiles/data_structures.dir/requires: CMakeFiles/data_structures.dir/stack/stack.c.o.requires

.PHONY : CMakeFiles/data_structures.dir/requires

CMakeFiles/data_structures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_structures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_structures.dir/clean

CMakeFiles/data_structures.dir/depend:
	cd /home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/regoeco/Documentos/projects/data-structures-in-C /home/regoeco/Documentos/projects/data-structures-in-C /home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug /home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug /home/regoeco/Documentos/projects/data-structures-in-C/cmake-build-debug/CMakeFiles/data_structures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_structures.dir/depend
