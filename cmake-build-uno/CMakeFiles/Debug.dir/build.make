# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = P:\LoRa\patenpflanze

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = P:\LoRa\patenpflanze\cmake-build-uno

# Utility rule file for Debug.

# Include the progress variables for this target.
include CMakeFiles\Debug.dir\progress.make

CMakeFiles\Debug:
	cd P:\LoRa\patenpflanze
	platformio -c clion run --target debug -euno
	cd P:\LoRa\patenpflanze\cmake-build-uno

Debug: CMakeFiles\Debug
Debug: CMakeFiles\Debug.dir\build.make

.PHONY : Debug

# Rule to build all files generated by this target.
CMakeFiles\Debug.dir\build: Debug

.PHONY : CMakeFiles\Debug.dir\build

CMakeFiles\Debug.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Debug.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Debug.dir\clean

CMakeFiles\Debug.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" P:\LoRa\patenpflanze P:\LoRa\patenpflanze P:\LoRa\patenpflanze\cmake-build-uno P:\LoRa\patenpflanze\cmake-build-uno P:\LoRa\patenpflanze\cmake-build-uno\CMakeFiles\Debug.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Debug.dir\depend

