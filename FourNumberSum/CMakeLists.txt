cmake_minimum_required(VERSION 3.26)
project(FourNumbersSum)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} solution.cc)
target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} gtest_main)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)