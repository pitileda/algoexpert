cmake_minimum_required(VERSION 3.26)
project(ThreeNumberSum)

include(FetchContent)
FetchContent_Declare(
  googletest
  url https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}1 solution1.cc)
target_include_directories(${PROJECT_NAME}1 PRIVATE .)
target_link_libraries(${PROJECT_NAME}1 gtest_main)
target_compile_features(${PROJECT_NAME}1 PRIVATE cxx_std_17)

add_executable(${PROJECT_NAME}2 solution2.cc)
target_include_directories(${PROJECT_NAME}2 PRIVATE .)
target_link_libraries(${PROJECT_NAME}2 gtest_main)
target_compile_features(${PROJECT_NAME}2 PRIVATE cxx_std_17)