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
    TileType* m_tileType;
public:
    IState() {
        m_tileType = nullptr;
    }
    virtual ~IState() = default;
    virtual IState* handleInput(const Input& input) const = 0;

    TileType* getTileType() const{
        return m_tileType;
    }
};

