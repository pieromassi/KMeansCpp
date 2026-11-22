cmake_minimum_required(VERSION 3.16)

project(KMeansCpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kmeans
    src/main.cpp
    src/kmeans.cpp
)

add_executable(test_distance tests/test_distance.cpp src/kmeans.cpp)
target_include_directories(test_distance PRIVATE include)

enable_testing()
add_test(NAME distance COMMAND test_distance)

add_executable(test_centroids_init
    tests/test_centroids_init.cpp
    src/kmeans.cpp
)
target_include_directories(test_centroids_init PRIVATE include)

add_test(NAME test_centroids_init COMMAND test_centroids_init)

target_include_directories(kmeans PRIVATE include)