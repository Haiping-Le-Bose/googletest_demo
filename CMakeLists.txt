cmake_minimum_required(VERSION 3.14)
project(CalculatorTest)

set(CMAKE_CXX_STANDARD 11)

# ============================ Introduce googletest begin ============================
# The reason that we use this method can be found in the following link:
# https://github.com/google/googletest/blob/main/googletest/README.md#build-with-cmake
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# ============================ Introduce googletest end ==============================

include_directories(include)
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(main ${SOURCES})

# Now simply link against gtest as needed.
add_executable(CalculatorTest test/CalculatorTest.cpp src/Calculator.cpp)
target_link_libraries(CalculatorTest gtest)