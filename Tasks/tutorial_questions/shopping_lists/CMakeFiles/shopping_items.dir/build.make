# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists

# Include any dependencies generated for this target.
include CMakeFiles/shopping_items.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/shopping_items.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/shopping_items.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shopping_items.dir/flags.make

CMakeFiles/shopping_items.dir/shopping_items.cpp.o: CMakeFiles/shopping_items.dir/flags.make
CMakeFiles/shopping_items.dir/shopping_items.cpp.o: shopping_items.cpp
CMakeFiles/shopping_items.dir/shopping_items.cpp.o: CMakeFiles/shopping_items.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shopping_items.dir/shopping_items.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/shopping_items.dir/shopping_items.cpp.o -MF CMakeFiles/shopping_items.dir/shopping_items.cpp.o.d -o CMakeFiles/shopping_items.dir/shopping_items.cpp.o -c /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists/shopping_items.cpp

CMakeFiles/shopping_items.dir/shopping_items.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/shopping_items.dir/shopping_items.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists/shopping_items.cpp > CMakeFiles/shopping_items.dir/shopping_items.cpp.i

CMakeFiles/shopping_items.dir/shopping_items.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/shopping_items.dir/shopping_items.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists/shopping_items.cpp -o CMakeFiles/shopping_items.dir/shopping_items.cpp.s

# Object files for target shopping_items
shopping_items_OBJECTS = \
"CMakeFiles/shopping_items.dir/shopping_items.cpp.o"

# External object files for target shopping_items
shopping_items_EXTERNAL_OBJECTS =

shopping_items: CMakeFiles/shopping_items.dir/shopping_items.cpp.o
shopping_items: CMakeFiles/shopping_items.dir/build.make
shopping_items: CMakeFiles/shopping_items.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shopping_items"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shopping_items.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shopping_items.dir/build: shopping_items
.PHONY : CMakeFiles/shopping_items.dir/build

CMakeFiles/shopping_items.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shopping_items.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shopping_items.dir/clean

CMakeFiles/shopping_items.dir/depend:
	cd /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists /Users/lukefriggieri/Desktop/Notes/University/YR2/CPS2004/Code/Tasks/tutorial_questions/shopping_lists/CMakeFiles/shopping_items.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/shopping_items.dir/depend

