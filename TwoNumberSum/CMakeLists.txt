cmake_minimum_required(VERSION 3.26)
project(TwoNumbersSum)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME}1 solution1.cc)
target_link_libraries(${PROJECT_NAME}1 gtest_main)
target_include_directories(${PROJECT_NAME}1 PRIVATE .)

add_executable(${PROJECT_NAME}2 solution2.cc)
target_link_libraries(${PROJECT_NAME}2 gtest_main)
target_include_directories(${PROJECT_NAME}2 PRIVATE .)

add_executable(${PROJECT_NAME}3 solution3.cc)
target_link_libraries(${PROJECT_NAME}3 gtest_main)
target_include_directories(${PROJECT_NAME}3 PRIVATE .)

add_test(NAME sol1_tests COMMAND ${PROJECT_NAME}1)
add_test(NAME sol2_tests COMMAND ${PROJECT_NAME}2)
add_test(NAME sol3_tests COMMAND ${PROJECT_NAME}3)
enable_testing()