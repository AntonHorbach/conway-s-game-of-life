cmake_minimum_required(VERSION 3.0.0)
project(game_of_life VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(game_of_life src/game/main.cpp src/game/Game.cpp)
                
target_link_libraries(game_of_life SDL2 SDL2_image SDL2_ttf)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)