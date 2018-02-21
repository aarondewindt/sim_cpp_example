# Main CMakeLists file.

# Configure project
cmake_minimum_required(VERSION 3.6)
project(sim_cpp_example)
set(CMAKE_CXX_STANDARD 14)
set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
include(CTest)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Inlcude google test
add_subdirectory(libs/googletest)
include_directories(libs/googletest/googletest/include)
include_directories(libs/googletest/googlemock/include)

find_package(Boost 1.55.0 REQUIRED COMPONENTS system filesystem locale)
if (Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIR})
    link_libraries(${Boost_LIBRARIES})
else()
    error("Boost not found")
endif()

# Include eigen
include_directories(libs/eigen-git-mirror)

# Include python (needed for matplotlib)
find_package(PythonLibs 2.7)
include_directories(${PYTHON_INCLUDE_DIRS})
link_libraries(${PYTHON_LIBRARIES})

# Include matplotlib
include_directories(libs/matplotlib-cpp)

# Include directories
include_directories(inc)

# Main application
add_subdirectory(src)

# Unit tests
add_subdirectory(test)

# Spikes
add_subdirectory(spike)
