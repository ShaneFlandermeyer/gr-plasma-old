# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/shane/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/shane/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shane/src/oot-modules/gr-plasma

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shane/src/oot-modules/gr-plasma/build

# Utility rule file for pygen_python_plasma_70488.

# Include any custom commands dependencies for this target.
include python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/compiler_depend.make

# Include the progress variables for this target.
include python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/progress.make

python/plasma/CMakeFiles/pygen_python_plasma_70488: python/plasma/__init__.pyc
python/plasma/CMakeFiles/pygen_python_plasma_70488: python/plasma/__init__.pyo

python/plasma/__init__.pyc: ../python/plasma/__init__.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shane/src/oot-modules/gr-plasma/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating __init__.pyc"
	cd /home/shane/src/oot-modules/gr-plasma/build/python/plasma && /usr/bin/python3 /home/shane/src/oot-modules/gr-plasma/build/python_compile_helper.py /home/shane/src/oot-modules/gr-plasma/python/plasma/__init__.py /home/shane/src/oot-modules/gr-plasma/build/python/plasma/__init__.pyc

python/plasma/__init__.pyo: ../python/plasma/__init__.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shane/src/oot-modules/gr-plasma/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating __init__.pyo"
	cd /home/shane/src/oot-modules/gr-plasma/build/python/plasma && /usr/bin/python3 -O /home/shane/src/oot-modules/gr-plasma/build/python_compile_helper.py /home/shane/src/oot-modules/gr-plasma/python/plasma/__init__.py /home/shane/src/oot-modules/gr-plasma/build/python/plasma/__init__.pyo

pygen_python_plasma_70488: python/plasma/CMakeFiles/pygen_python_plasma_70488
pygen_python_plasma_70488: python/plasma/__init__.pyc
pygen_python_plasma_70488: python/plasma/__init__.pyo
pygen_python_plasma_70488: python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/build.make
.PHONY : pygen_python_plasma_70488

# Rule to build all files generated by this target.
python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/build: pygen_python_plasma_70488
.PHONY : python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/build

python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/clean:
	cd /home/shane/src/oot-modules/gr-plasma/build/python/plasma && $(CMAKE_COMMAND) -P CMakeFiles/pygen_python_plasma_70488.dir/cmake_clean.cmake
.PHONY : python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/clean

python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/depend:
	cd /home/shane/src/oot-modules/gr-plasma/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shane/src/oot-modules/gr-plasma /home/shane/src/oot-modules/gr-plasma/python/plasma /home/shane/src/oot-modules/gr-plasma/build /home/shane/src/oot-modules/gr-plasma/build/python/plasma /home/shane/src/oot-modules/gr-plasma/build/python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : python/plasma/CMakeFiles/pygen_python_plasma_70488.dir/depend

