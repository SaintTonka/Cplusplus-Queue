# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\danii\Desktop\Cplusplus-Queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\danii\Desktop\Cplusplus-Queue\build

# Include any dependencies generated for this target.
include test/CMakeFiles/Test_Events.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/Test_Events.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Test_Events.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Test_Events.dir/flags.make

test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj: test/CMakeFiles/Test_Events.dir/flags.make
test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj: test/CMakeFiles/Test_Events.dir/includes_CXX.rsp
test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj: C:/Users/danii/Desktop/Cplusplus-Queue/test/Test_Events.cpp
test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj: test/CMakeFiles/Test_Events.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\danii\Desktop\Cplusplus-Queue\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj"
	cd /d C:\Users\danii\Desktop\Cplusplus-Queue\build\test && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj -MF CMakeFiles\Test_Events.dir\Test_Events.cpp.obj.d -o CMakeFiles\Test_Events.dir\Test_Events.cpp.obj -c C:\Users\danii\Desktop\Cplusplus-Queue\test\Test_Events.cpp

test/CMakeFiles/Test_Events.dir/Test_Events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test_Events.dir/Test_Events.cpp.i"
	cd /d C:\Users\danii\Desktop\Cplusplus-Queue\build\test && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\danii\Desktop\Cplusplus-Queue\test\Test_Events.cpp > CMakeFiles\Test_Events.dir\Test_Events.cpp.i

test/CMakeFiles/Test_Events.dir/Test_Events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test_Events.dir/Test_Events.cpp.s"
	cd /d C:\Users\danii\Desktop\Cplusplus-Queue\build\test && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\danii\Desktop\Cplusplus-Queue\test\Test_Events.cpp -o CMakeFiles\Test_Events.dir\Test_Events.cpp.s

# Object files for target Test_Events
Test_Events_OBJECTS = \
"CMakeFiles/Test_Events.dir/Test_Events.cpp.obj"

# External object files for target Test_Events
Test_Events_EXTERNAL_OBJECTS =

test/Test_Events.exe: test/CMakeFiles/Test_Events.dir/Test_Events.cpp.obj
test/Test_Events.exe: test/CMakeFiles/Test_Events.dir/build.make
test/Test_Events.exe: lib/libgtestd.a
test/Test_Events.exe: test/CMakeFiles/Test_Events.dir/linkLibs.rsp
test/Test_Events.exe: test/CMakeFiles/Test_Events.dir/objects1.rsp
test/Test_Events.exe: test/CMakeFiles/Test_Events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\danii\Desktop\Cplusplus-Queue\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test_Events.exe"
	cd /d C:\Users\danii\Desktop\Cplusplus-Queue\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test_Events.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/Test_Events.dir/build: test/Test_Events.exe
.PHONY : test/CMakeFiles/Test_Events.dir/build

test/CMakeFiles/Test_Events.dir/clean:
	cd /d C:\Users\danii\Desktop\Cplusplus-Queue\build\test && $(CMAKE_COMMAND) -P CMakeFiles\Test_Events.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/Test_Events.dir/clean

test/CMakeFiles/Test_Events.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\danii\Desktop\Cplusplus-Queue C:\Users\danii\Desktop\Cplusplus-Queue\test C:\Users\danii\Desktop\Cplusplus-Queue\build C:\Users\danii\Desktop\Cplusplus-Queue\build\test C:\Users\danii\Desktop\Cplusplus-Queue\build\test\CMakeFiles\Test_Events.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/Test_Events.dir/depend
