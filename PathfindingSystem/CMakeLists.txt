set(PATHFINDING_SYSTEM_HEADERS
        PathfindingSystem.hpp
         "Astar/astarsearch.h" "Astar/Node.h"  "Astar/Grid.h" "Astar/PortalNode.h")

set(PATHFINDING_SYSTEM_SOURCES
        PathfindingSystem.cpp
        )

add_library(PathfindingSystem STATIC ${PATHFINDING_SYSTEM_HEADERS} ${PATHFINDING_SYSTEM_SOURCES})

install(TARGETS PathfindingSystem
        LIBRARY DESTINATION PathfindingSystemLib
        ARCHIVE DESTINATION PathfindingSystemLib
        )