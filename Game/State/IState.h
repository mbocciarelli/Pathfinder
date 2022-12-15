#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "../Entity/Tile.hpp"

class IState {
protected :
    TileType m_tileType;
public:
    IState()
    {
        m_tileType = TileType::Ground;
    }
    virtual ~IState() = default;
    virtual IState* handleInput(IState* currentState, const sf::Keyboard::Key& input) const = 0;

    TileType getType() const{
        return m_tileType;
    }
};

