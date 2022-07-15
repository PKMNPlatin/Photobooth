cmake_minimum_required(VERSION 3.18.4)
project(Photobooth VERSION 1.0.0 LANGUAGES CXX)

# --------------------------------------------------------------------------------------------------------
# Create library
# --------------------------------------------------------------------------------------------------------

file(GLOB src "src/*.cpp")

add_executable(${PROJECT_NAME} src/main.cpp ${src} include/Utils.h)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED ON)

#add_definitions( -DADD_GPIO_SUPPORT )

# --------------------------------------------------------------------------------------------------------
# Find packages
# --------------------------------------------------------------------------------------------------------
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

# --------------------------------------------------------------------------------------------------------
# Include "include" folder
# --------------------------------------------------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PUBLIC include)

# --------------------------------------------------------------------------------------------------------
# Link required libraries
# --------------------------------------------------------------------------------------------------------

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

target_link_libraries(${PROJECT_NAME} gphoto2pp)
target_link_libraries(${PROJECT_NAME} gphoto2)
target_link_libraries(${PROJECT_NAME} wiringPi)