cmake_minimum_required(VERSION 3.2)

# Use the C++11 standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Pong)
add_subdirectory(src)

# Make sure our Pong game is set on planet Earth.
enable_testing()
add_test(NAME on_earth COMMAND Pong)
set_tests_properties(on_earth PROPERTIES
    PASS_REGULAR_EXPRESSION "g = 9\.80665")
