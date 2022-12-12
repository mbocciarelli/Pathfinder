set(GAME_HEADERS
           "Scene.hpp" "Component/Component.hpp" "Component/Sprite.hpp"   "Entity/Tile.hpp" "SpriteRenderer.hpp" "Entity/SquareTile.hpp")

set(GAME_SOURCES
        main.cpp
           "Scene.cpp")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
add_executable(Game ${GAME_HEADERS} ${GAME_SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/PathfindingSystem)
target_link_libraries(Game PathfindingSystem sfml-system sfml-network sfml-graphics sfml-window)

install(TARGETS Game RUNTIME DESTINATION bin)