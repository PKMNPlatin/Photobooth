# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = "/run/media/jona/M2 Storage/Development/Photobooth/gallery"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/run/media/jona/M2 Storage/Development/Photobooth/gallery/build"

# Include any dependencies generated for this target.
include CMakeFiles/Gallery.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Gallery.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Gallery.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gallery.dir/flags.make

CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o: CMakeFiles/Gallery.dir/flags.make
CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o: ../src/ImageGallery.cpp
CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o: CMakeFiles/Gallery.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o -MF CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o.d -o CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o -c "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/ImageGallery.cpp"

CMakeFiles/Gallery.dir/src/ImageGallery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gallery.dir/src/ImageGallery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/ImageGallery.cpp" > CMakeFiles/Gallery.dir/src/ImageGallery.cpp.i

CMakeFiles/Gallery.dir/src/ImageGallery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gallery.dir/src/ImageGallery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/ImageGallery.cpp" -o CMakeFiles/Gallery.dir/src/ImageGallery.cpp.s

CMakeFiles/Gallery.dir/src/ImageView.cpp.o: CMakeFiles/Gallery.dir/flags.make
CMakeFiles/Gallery.dir/src/ImageView.cpp.o: ../src/ImageView.cpp
CMakeFiles/Gallery.dir/src/ImageView.cpp.o: CMakeFiles/Gallery.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Gallery.dir/src/ImageView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gallery.dir/src/ImageView.cpp.o -MF CMakeFiles/Gallery.dir/src/ImageView.cpp.o.d -o CMakeFiles/Gallery.dir/src/ImageView.cpp.o -c "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/ImageView.cpp"

CMakeFiles/Gallery.dir/src/ImageView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gallery.dir/src/ImageView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/ImageView.cpp" > CMakeFiles/Gallery.dir/src/ImageView.cpp.i

CMakeFiles/Gallery.dir/src/ImageView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gallery.dir/src/ImageView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/ImageView.cpp" -o CMakeFiles/Gallery.dir/src/ImageView.cpp.s

CMakeFiles/Gallery.dir/src/Texture.cpp.o: CMakeFiles/Gallery.dir/flags.make
CMakeFiles/Gallery.dir/src/Texture.cpp.o: ../src/Texture.cpp
CMakeFiles/Gallery.dir/src/Texture.cpp.o: CMakeFiles/Gallery.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Gallery.dir/src/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gallery.dir/src/Texture.cpp.o -MF CMakeFiles/Gallery.dir/src/Texture.cpp.o.d -o CMakeFiles/Gallery.dir/src/Texture.cpp.o -c "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/Texture.cpp"

CMakeFiles/Gallery.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gallery.dir/src/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/Texture.cpp" > CMakeFiles/Gallery.dir/src/Texture.cpp.i

CMakeFiles/Gallery.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gallery.dir/src/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/Texture.cpp" -o CMakeFiles/Gallery.dir/src/Texture.cpp.s

CMakeFiles/Gallery.dir/src/Window.cpp.o: CMakeFiles/Gallery.dir/flags.make
CMakeFiles/Gallery.dir/src/Window.cpp.o: ../src/Window.cpp
CMakeFiles/Gallery.dir/src/Window.cpp.o: CMakeFiles/Gallery.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Gallery.dir/src/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gallery.dir/src/Window.cpp.o -MF CMakeFiles/Gallery.dir/src/Window.cpp.o.d -o CMakeFiles/Gallery.dir/src/Window.cpp.o -c "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/Window.cpp"

CMakeFiles/Gallery.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gallery.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/Window.cpp" > CMakeFiles/Gallery.dir/src/Window.cpp.i

CMakeFiles/Gallery.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gallery.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/Window.cpp" -o CMakeFiles/Gallery.dir/src/Window.cpp.s

CMakeFiles/Gallery.dir/src/stb_image.cpp.o: CMakeFiles/Gallery.dir/flags.make
CMakeFiles/Gallery.dir/src/stb_image.cpp.o: ../src/stb_image.cpp
CMakeFiles/Gallery.dir/src/stb_image.cpp.o: CMakeFiles/Gallery.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Gallery.dir/src/stb_image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gallery.dir/src/stb_image.cpp.o -MF CMakeFiles/Gallery.dir/src/stb_image.cpp.o.d -o CMakeFiles/Gallery.dir/src/stb_image.cpp.o -c "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/stb_image.cpp"

CMakeFiles/Gallery.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gallery.dir/src/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/stb_image.cpp" > CMakeFiles/Gallery.dir/src/stb_image.cpp.i

CMakeFiles/Gallery.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gallery.dir/src/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/run/media/jona/M2 Storage/Development/Photobooth/gallery/src/stb_image.cpp" -o CMakeFiles/Gallery.dir/src/stb_image.cpp.s

# Object files for target Gallery
Gallery_OBJECTS = \
"CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o" \
"CMakeFiles/Gallery.dir/src/ImageView.cpp.o" \
"CMakeFiles/Gallery.dir/src/Texture.cpp.o" \
"CMakeFiles/Gallery.dir/src/Window.cpp.o" \
"CMakeFiles/Gallery.dir/src/stb_image.cpp.o"

# External object files for target Gallery
Gallery_EXTERNAL_OBJECTS =

libGallery.so: CMakeFiles/Gallery.dir/src/ImageGallery.cpp.o
libGallery.so: CMakeFiles/Gallery.dir/src/ImageView.cpp.o
libGallery.so: CMakeFiles/Gallery.dir/src/Texture.cpp.o
libGallery.so: CMakeFiles/Gallery.dir/src/Window.cpp.o
libGallery.so: CMakeFiles/Gallery.dir/src/stb_image.cpp.o
libGallery.so: CMakeFiles/Gallery.dir/build.make
libGallery.so: /usr/lib/libglfw.so.3.3
libGallery.so: /usr/lib/libGLX.so
libGallery.so: /usr/lib/libOpenGL.so
libGallery.so: CMakeFiles/Gallery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libGallery.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gallery.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gallery.dir/build: libGallery.so
.PHONY : CMakeFiles/Gallery.dir/build

CMakeFiles/Gallery.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gallery.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gallery.dir/clean

CMakeFiles/Gallery.dir/depend:
	cd "/run/media/jona/M2 Storage/Development/Photobooth/gallery/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/run/media/jona/M2 Storage/Development/Photobooth/gallery" "/run/media/jona/M2 Storage/Development/Photobooth/gallery" "/run/media/jona/M2 Storage/Development/Photobooth/gallery/build" "/run/media/jona/M2 Storage/Development/Photobooth/gallery/build" "/run/media/jona/M2 Storage/Development/Photobooth/gallery/build/CMakeFiles/Gallery.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Gallery.dir/depend

