add_executable(spike_fibonacci fibonacci.cpp)

add_executable(spike_boost boost.cpp)
target_link_libraries(spike_boost ${Boost_LIBRARIES})

add_executable(spike_eigen eigen.cpp)
target_link_libraries (spike_eigen Eigen3::Eigen)
