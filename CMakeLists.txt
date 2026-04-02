cmake_minimum_required(VERSION 3.16)
project(ErrorStateKalmanFilter)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

add_executable(ErrorStateKalmanFilter
    src/main.cpp
    src/utils/motion_data.cpp
    src/utils/sensor_data.cpp
    src/utils/RunFilter.cpp
    src/filter/filter.cpp
    src/data/data.cpp
)

target_link_libraries(ErrorStateKalmanFilter Eigen3::Eigen)
