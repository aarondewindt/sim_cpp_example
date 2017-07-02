cmake_minimum_required(VERSION 3.6)
project(sim_cpp_example)

set(CMAKE_CXX_STANDARD 14)

# Include directories
# ===================
include_directories(inc)

# Main application
# ================
set(SOURCE_FILES src/main.cpp inc/shape.h src/rectangle.cpp inc/rectangle.h src/triangle.cpp inc/triangle.h)
add_executable(sim_cpp_example ${SOURCE_FILES})


# Spikes
# ======
add_executable(spike_fibonacci spike/fibonacci.cpp)