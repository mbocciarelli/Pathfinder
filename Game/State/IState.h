#pragma once

#include "../Entity/Tile.hpp"

enum class Input {
    Start = 0,
    End,
    Ground,
    Wall,
    Run,
    TileMap
};

class IState {
private :
    TileType m_type;
public:
    virtual ~IState() = default;
    virtual IState* handleInput(const Input& input) const = 0;
    virtual void UpdateTile(Tile& tile) const = 0;
};

