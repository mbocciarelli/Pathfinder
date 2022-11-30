set(GAME_HEADERS
        includes/main.hpp
        )

set(GAME_SOURCES
        src/main.cpp
        )

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
add_executable(Game ${GAME_HEADERS} ${GAME_SOURCES})
target_link_libraries(Game PathfindingSystem sfml-system sfml-network sfml-graphics sfml-window)

install(TARGETS Game RUNTIME DESTINATION bin)