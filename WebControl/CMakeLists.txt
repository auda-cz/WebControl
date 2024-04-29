cmake_minimum_required(VERSION 3.0)
project(WebControl)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)  # Crow requires at least C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Crow
# Assuming Crow is in a standard include path or in a subdirectory of your project
include_directories(/usr/local/include)

# Create the executable
add_executable(WebControl WebControl.cpp)

# If Crow is installed system-wide, you typically don't need to link libraries
# If Crow is not installed system-wide, you might need to link against Boost libraries here
# target_link_libraries(MyControlApp pthread)
