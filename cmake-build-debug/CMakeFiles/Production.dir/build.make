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
CMAKE_BINARY_DIR = P:\LoRa\patenpflanze\cmake-build-debug

# Utility rule file for Production.

# Include the progress variables for this target.
include CMakeFiles\Production.dir\progress.make

CMakeFiles\Production:
	cd P:\LoRa\patenpflanze
	platformio -c clion run -eDebug
	cd P:\LoRa\patenpflanze\cmake-build-debug

Production: CMakeFiles\Production
Production: CMakeFiles\Production.dir\build.make

.PHONY : Production

# Rule to build all files generated by this target.
CMakeFiles\Production.dir\build: Production

.PHONY : CMakeFiles\Production.dir\build

CMakeFiles\Production.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Production.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Production.dir\clean

CMakeFiles\Production.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" P:\LoRa\patenpflanze P:\LoRa\patenpflanze P:\LoRa\patenpflanze\cmake-build-debug P:\LoRa\patenpflanze\cmake-build-debug P:\LoRa\patenpflanze\cmake-build-debug\CMakeFiles\Production.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Production.dir\depend

