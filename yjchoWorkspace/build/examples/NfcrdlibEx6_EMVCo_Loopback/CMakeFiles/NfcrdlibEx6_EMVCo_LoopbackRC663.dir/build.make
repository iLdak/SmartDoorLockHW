# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/pi/Downloads/NFC Reader Library for Linux V.4.0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build"

# Include any dependencies generated for this target.
include examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/depend.make

# Include the progress variables for this target.
include examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/progress.make

# Include the compile flags for this target's objects.
include examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/flags.make

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/flags.make
examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o: ../examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_Loopback.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o"
	cd "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback" && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o   -c "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_Loopback.c"

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.i"
	cd "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback" && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_Loopback.c" > CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.i

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.s"
	cd "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback" && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_Loopback.c" -o CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.s

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.requires:
.PHONY : examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.requires

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.provides: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.requires
	$(MAKE) -f examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/build.make examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.provides.build
.PHONY : examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.provides

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.provides.build: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o

# Object files for target NfcrdlibEx6_EMVCo_LoopbackRC663
NfcrdlibEx6_EMVCo_LoopbackRC663_OBJECTS = \
"CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o"

# External object files for target NfcrdlibEx6_EMVCo_LoopbackRC663
NfcrdlibEx6_EMVCo_LoopbackRC663_EXTERNAL_OBJECTS =

examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_LoopbackRC663: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o
examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_LoopbackRC663: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/build.make
examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_LoopbackRC663: linux/libNxpRdLibLinuxRC663.a
examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_LoopbackRC663: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable NfcrdlibEx6_EMVCo_LoopbackRC663"
	cd "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/build: examples/NfcrdlibEx6_EMVCo_Loopback/NfcrdlibEx6_EMVCo_LoopbackRC663
.PHONY : examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/build

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/requires: examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/NfcrdlibEx6_EMVCo_Loopback.c.o.requires
.PHONY : examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/requires

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/clean:
	cd "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback" && $(CMAKE_COMMAND) -P CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/cmake_clean.cmake
.PHONY : examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/clean

examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/depend:
	cd "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/pi/Downloads/NFC Reader Library for Linux V.4.0" "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/examples/NfcrdlibEx6_EMVCo_Loopback" "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build" "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback" "/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : examples/NfcrdlibEx6_EMVCo_Loopback/CMakeFiles/NfcrdlibEx6_EMVCo_LoopbackRC663.dir/depend

