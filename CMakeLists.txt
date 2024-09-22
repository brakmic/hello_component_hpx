cmake_minimum_required(VERSION 3.19)
project(HelloComponentHpx CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Find and link HPX
find_package(HPX REQUIRED)

# Create the executable
add_executable(hello_component_hpx src/main.cpp src/hello_component.cpp)

# Link libraries
target_link_libraries(hello_component_hpx HPX::hpx HPX::wrap_main HPX::iostreams_component)
