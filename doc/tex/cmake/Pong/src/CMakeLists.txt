# Add an executable.
add_executable(Pong game.cpp logic.cpp)

# Link to our Physics library.
add_subdirectory(PhysicsLib)
include_directories(PhysicsLib)
target_link_libraries(Pong Physics)

