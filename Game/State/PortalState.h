#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "IState.h"

class PortalState :public IState {
public:
    PortalState()
    {
        m_tileType = TileType::Portal;
    }
    ~PortalState() = default;

    IState* handleInput(IState* currentState ,const sf::Keyboard::Key& input) const override;

};

