# Main CMakeLists file.

# Configure project
cmake_minimum_required(VERSION 3.6)
project(sim_cpp_example)
set(CMAKE_CXX_STANDARD 14)
set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
include(CTest)

# Download project is used to download external git repositories to
# our project.
include(DownloadProject.cmake)

# Download google test.
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Inlcude google test to our project
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
include_directories(${googletest_SOURCE_DIR}/googletest/include)
include_directories(${googletest_SOURCE_DIR}/googlemock/include)

find_package(Boost 1.55.0 REQUIRED COMPONENTS system filesystem locale)
if (Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIR})
else()
    error("Boost not found")
endif()

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# Include directories
include_directories(inc)

# Main application
add_subdirectory(src)

# Unit tests
add_subdirectory(test)

# Spikes
add_subdirectory(spike)
