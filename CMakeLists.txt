cmake_minimum_required(VERSION 3.9)
project(game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(/source)

set(CMAKE_CXX_STANDARD 14)

add_executable(game source/main.cpp source/game.cpp source/headers/game.h source/figure.cpp source/headers/figure.h source/player.cpp source/headers/player.h source/Map.cpp source/headers/Map.h source/Input.cpp source/headers/Input.h source/enemy.cpp source/headers/enemy.h)

target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} -lmingw32 -lSDL2main -lSDL2 -mwindows)
