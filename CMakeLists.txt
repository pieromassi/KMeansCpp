cmake_minimum_required(VERSION 3.16)

project(KMeansCpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kmeans
    src/main.cpp
    src/kmeans.cpp
)

target_include_directories(kmeans PRIVATE include)