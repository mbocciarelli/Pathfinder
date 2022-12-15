set(GAME_HEADERS
           Scene.hpp 
           Component/Component.hpp 
           Component/Sprite.hpp   
           Entity/Tile.hpp 
           SpriteRenderer.hpp
           Entity/SquareTile.hpp
           State/IState.h
           State/EndState.h 
           State/StartState.h 
           State/DefaultState.h 
           State/GroundState.h 
           State/WallState.h 
           State/RunState.h
         )

set(GAME_SOURCES
        main.cpp
        Scene.cpp
        State/DefaultState.cpp
        State/StartState.cpp
        State/EndState.cpp
        State/WallState.cpp
        State/GroundState.cpp
        State/RunState.cpp

         "Entity/Tile.cpp")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
add_executable(Game ${GAME_HEADERS} ${GAME_SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/PathfindingSystem)
include_directories(${CMAKE_SOURCE_DIR}/Game)
target_link_libraries(Game PathfindingSystem sfml-system sfml-network sfml-graphics sfml-window)
file(COPY Sprite DESTINATION ${CMAKE_BINARY_DIR})

install(TARGETS Game RUNTIME DESTINATION bin)