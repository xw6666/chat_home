# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wjr/chat_home

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wjr/chat_home/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/chat_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/server/CMakeFiles/chat_server.dir/compiler_depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/chat_server.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/chat_server.dir/flags.make

src/server/CMakeFiles/chat_server.dir/db/db.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/db/db.cc.o: /home/wjr/chat_home/src/server/db/db.cc
src/server/CMakeFiles/chat_server.dir/db/db.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/CMakeFiles/chat_server.dir/db/db.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/db/db.cc.o -MF CMakeFiles/chat_server.dir/db/db.cc.o.d -o CMakeFiles/chat_server.dir/db/db.cc.o -c /home/wjr/chat_home/src/server/db/db.cc

src/server/CMakeFiles/chat_server.dir/db/db.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/db/db.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/db/db.cc > CMakeFiles/chat_server.dir/db/db.cc.i

src/server/CMakeFiles/chat_server.dir/db/db.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/db/db.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/db/db.cc -o CMakeFiles/chat_server.dir/db/db.cc.s

src/server/CMakeFiles/chat_server.dir/chat_server.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/chat_server.cc.o: /home/wjr/chat_home/src/server/chat_server.cc
src/server/CMakeFiles/chat_server.dir/chat_server.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/server/CMakeFiles/chat_server.dir/chat_server.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/chat_server.cc.o -MF CMakeFiles/chat_server.dir/chat_server.cc.o.d -o CMakeFiles/chat_server.dir/chat_server.cc.o -c /home/wjr/chat_home/src/server/chat_server.cc

src/server/CMakeFiles/chat_server.dir/chat_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/chat_server.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/chat_server.cc > CMakeFiles/chat_server.dir/chat_server.cc.i

src/server/CMakeFiles/chat_server.dir/chat_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/chat_server.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/chat_server.cc -o CMakeFiles/chat_server.dir/chat_server.cc.s

src/server/CMakeFiles/chat_server.dir/chat_service.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/chat_service.cc.o: /home/wjr/chat_home/src/server/chat_service.cc
src/server/CMakeFiles/chat_server.dir/chat_service.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/server/CMakeFiles/chat_server.dir/chat_service.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/chat_service.cc.o -MF CMakeFiles/chat_server.dir/chat_service.cc.o.d -o CMakeFiles/chat_server.dir/chat_service.cc.o -c /home/wjr/chat_home/src/server/chat_service.cc

src/server/CMakeFiles/chat_server.dir/chat_service.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/chat_service.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/chat_service.cc > CMakeFiles/chat_server.dir/chat_service.cc.i

src/server/CMakeFiles/chat_server.dir/chat_service.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/chat_service.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/chat_service.cc -o CMakeFiles/chat_server.dir/chat_service.cc.s

src/server/CMakeFiles/chat_server.dir/friendmodel.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/friendmodel.cc.o: /home/wjr/chat_home/src/server/friendmodel.cc
src/server/CMakeFiles/chat_server.dir/friendmodel.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/server/CMakeFiles/chat_server.dir/friendmodel.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/friendmodel.cc.o -MF CMakeFiles/chat_server.dir/friendmodel.cc.o.d -o CMakeFiles/chat_server.dir/friendmodel.cc.o -c /home/wjr/chat_home/src/server/friendmodel.cc

src/server/CMakeFiles/chat_server.dir/friendmodel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/friendmodel.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/friendmodel.cc > CMakeFiles/chat_server.dir/friendmodel.cc.i

src/server/CMakeFiles/chat_server.dir/friendmodel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/friendmodel.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/friendmodel.cc -o CMakeFiles/chat_server.dir/friendmodel.cc.s

src/server/CMakeFiles/chat_server.dir/groupmodel.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/groupmodel.cc.o: /home/wjr/chat_home/src/server/groupmodel.cc
src/server/CMakeFiles/chat_server.dir/groupmodel.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/server/CMakeFiles/chat_server.dir/groupmodel.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/groupmodel.cc.o -MF CMakeFiles/chat_server.dir/groupmodel.cc.o.d -o CMakeFiles/chat_server.dir/groupmodel.cc.o -c /home/wjr/chat_home/src/server/groupmodel.cc

src/server/CMakeFiles/chat_server.dir/groupmodel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/groupmodel.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/groupmodel.cc > CMakeFiles/chat_server.dir/groupmodel.cc.i

src/server/CMakeFiles/chat_server.dir/groupmodel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/groupmodel.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/groupmodel.cc -o CMakeFiles/chat_server.dir/groupmodel.cc.s

src/server/CMakeFiles/chat_server.dir/main.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/main.cc.o: /home/wjr/chat_home/src/server/main.cc
src/server/CMakeFiles/chat_server.dir/main.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/server/CMakeFiles/chat_server.dir/main.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/main.cc.o -MF CMakeFiles/chat_server.dir/main.cc.o.d -o CMakeFiles/chat_server.dir/main.cc.o -c /home/wjr/chat_home/src/server/main.cc

src/server/CMakeFiles/chat_server.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/main.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/main.cc > CMakeFiles/chat_server.dir/main.cc.i

src/server/CMakeFiles/chat_server.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/main.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/main.cc -o CMakeFiles/chat_server.dir/main.cc.s

src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.o: /home/wjr/chat_home/src/server/offlinemsg_model.cc
src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.o -MF CMakeFiles/chat_server.dir/offlinemsg_model.cc.o.d -o CMakeFiles/chat_server.dir/offlinemsg_model.cc.o -c /home/wjr/chat_home/src/server/offlinemsg_model.cc

src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/offlinemsg_model.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/offlinemsg_model.cc > CMakeFiles/chat_server.dir/offlinemsg_model.cc.i

src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/offlinemsg_model.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/offlinemsg_model.cc -o CMakeFiles/chat_server.dir/offlinemsg_model.cc.s

src/server/CMakeFiles/chat_server.dir/user_model.cc.o: src/server/CMakeFiles/chat_server.dir/flags.make
src/server/CMakeFiles/chat_server.dir/user_model.cc.o: /home/wjr/chat_home/src/server/user_model.cc
src/server/CMakeFiles/chat_server.dir/user_model.cc.o: src/server/CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/server/CMakeFiles/chat_server.dir/user_model.cc.o"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/chat_server.dir/user_model.cc.o -MF CMakeFiles/chat_server.dir/user_model.cc.o.d -o CMakeFiles/chat_server.dir/user_model.cc.o -c /home/wjr/chat_home/src/server/user_model.cc

src/server/CMakeFiles/chat_server.dir/user_model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/user_model.cc.i"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wjr/chat_home/src/server/user_model.cc > CMakeFiles/chat_server.dir/user_model.cc.i

src/server/CMakeFiles/chat_server.dir/user_model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/user_model.cc.s"
	cd /home/wjr/chat_home/build/src/server && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wjr/chat_home/src/server/user_model.cc -o CMakeFiles/chat_server.dir/user_model.cc.s

# Object files for target chat_server
chat_server_OBJECTS = \
"CMakeFiles/chat_server.dir/db/db.cc.o" \
"CMakeFiles/chat_server.dir/chat_server.cc.o" \
"CMakeFiles/chat_server.dir/chat_service.cc.o" \
"CMakeFiles/chat_server.dir/friendmodel.cc.o" \
"CMakeFiles/chat_server.dir/groupmodel.cc.o" \
"CMakeFiles/chat_server.dir/main.cc.o" \
"CMakeFiles/chat_server.dir/offlinemsg_model.cc.o" \
"CMakeFiles/chat_server.dir/user_model.cc.o"

# External object files for target chat_server
chat_server_EXTERNAL_OBJECTS =

/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/db/db.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/chat_server.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/chat_service.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/friendmodel.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/groupmodel.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/main.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/offlinemsg_model.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/user_model.cc.o
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/build.make
/home/wjr/chat_home/bin/chat_server: src/server/CMakeFiles/chat_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/wjr/chat_home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable /home/wjr/chat_home/bin/chat_server"
	cd /home/wjr/chat_home/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chat_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/chat_server.dir/build: /home/wjr/chat_home/bin/chat_server
.PHONY : src/server/CMakeFiles/chat_server.dir/build

src/server/CMakeFiles/chat_server.dir/clean:
	cd /home/wjr/chat_home/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/chat_server.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/chat_server.dir/clean

src/server/CMakeFiles/chat_server.dir/depend:
	cd /home/wjr/chat_home/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wjr/chat_home /home/wjr/chat_home/src/server /home/wjr/chat_home/build /home/wjr/chat_home/build/src/server /home/wjr/chat_home/build/src/server/CMakeFiles/chat_server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/server/CMakeFiles/chat_server.dir/depend

