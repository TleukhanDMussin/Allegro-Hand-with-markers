# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rustam/allegro_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rustam/allegro_ws/build

# Include any dependencies generated for this target.
include allegro_hand/CMakeFiles/allegro_hand_uname.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include allegro_hand/CMakeFiles/allegro_hand_uname.dir/compiler_depend.make

# Include the progress variables for this target.
include allegro_hand/CMakeFiles/allegro_hand_uname.dir/progress.make

# Include the compile flags for this target's objects.
include allegro_hand/CMakeFiles/allegro_hand_uname.dir/flags.make

allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o: allegro_hand/CMakeFiles/allegro_hand_uname.dir/flags.make
allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o: /home/rustam/allegro_ws/src/allegro_hand/src/allegro_hand_uname.cpp
allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o: allegro_hand/CMakeFiles/allegro_hand_uname.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rustam/allegro_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o"
	cd /home/rustam/allegro_ws/build/allegro_hand && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o -MF CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o.d -o CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o -c /home/rustam/allegro_ws/src/allegro_hand/src/allegro_hand_uname.cpp

allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.i"
	cd /home/rustam/allegro_ws/build/allegro_hand && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rustam/allegro_ws/src/allegro_hand/src/allegro_hand_uname.cpp > CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.i

allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.s"
	cd /home/rustam/allegro_ws/build/allegro_hand && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rustam/allegro_ws/src/allegro_hand/src/allegro_hand_uname.cpp -o CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.s

# Object files for target allegro_hand_uname
allegro_hand_uname_OBJECTS = \
"CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o"

# External object files for target allegro_hand_uname
allegro_hand_uname_EXTERNAL_OBJECTS =

/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: allegro_hand/CMakeFiles/allegro_hand_uname.dir/src/allegro_hand_uname.cpp.o
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: allegro_hand/CMakeFiles/allegro_hand_uname.dir/build.make
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /home/rustam/allegro_ws/devel/lib/liballegro_hand_driver.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /home/rustam/allegro_ws/devel/lib/libBHand.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/libpcan.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/libroscpp.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/librosconsole.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/librostime.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /opt/ros/melodic/lib/libcpp_common.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname: allegro_hand/CMakeFiles/allegro_hand_uname.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rustam/allegro_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname"
	cd /home/rustam/allegro_ws/build/allegro_hand && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_hand_uname.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
allegro_hand/CMakeFiles/allegro_hand_uname.dir/build: /home/rustam/allegro_ws/devel/lib/allegro_hand/allegro_hand_uname
.PHONY : allegro_hand/CMakeFiles/allegro_hand_uname.dir/build

allegro_hand/CMakeFiles/allegro_hand_uname.dir/clean:
	cd /home/rustam/allegro_ws/build/allegro_hand && $(CMAKE_COMMAND) -P CMakeFiles/allegro_hand_uname.dir/cmake_clean.cmake
.PHONY : allegro_hand/CMakeFiles/allegro_hand_uname.dir/clean

allegro_hand/CMakeFiles/allegro_hand_uname.dir/depend:
	cd /home/rustam/allegro_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rustam/allegro_ws/src /home/rustam/allegro_ws/src/allegro_hand /home/rustam/allegro_ws/build /home/rustam/allegro_ws/build/allegro_hand /home/rustam/allegro_ws/build/allegro_hand/CMakeFiles/allegro_hand_uname.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : allegro_hand/CMakeFiles/allegro_hand_uname.dir/depend

