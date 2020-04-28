cmake_minimum_required(VERSION 3.13)  # CMake version check
project(hearts_proj)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES hearts.cpp deck.cpp card.cpp player.cpp game.cpp random_ai.cpp low_ai.cpp human_player.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(hearts_proj ${SOURCE_FILES})