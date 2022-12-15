#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "State/IState.h"

class DefaultState : public IState {
public:
    DefaultState()
    {
        m_tileType = TileType::Ground;
    }
    ~DefaultState() override = default;

    IState* handleInput(IState* currentState, const sf::Keyboard::Key& input) const override;

};