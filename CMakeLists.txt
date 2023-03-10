cmake_minimum_required(VERSION 3.14)
project(Sudoku_cpp)
add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra -std=c++17)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}-ut src/tests/tests.cpp)
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)