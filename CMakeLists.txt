cmake_minimum_required(VERSION 3.9)
project(game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(/source)

set(CMAKE_CXX_STANDARD 14)

add_executable(game source/main.cpp source/Game.cpp headers/Game.h source/Figure.cpp headers/Figure.h source/Player.cpp headers/Player.h source/Map.cpp headers/Map.h source/Input.cpp headers/Input.h source/Enemy.cpp headers/Enemy.h source/Handle.cpp headers/Handle.h source/Sword.cpp headers/Sword.h source/Item.cpp headers/Item.h)

target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} -lmingw32 -lSDL2main -lSDL2 -mwindows)
