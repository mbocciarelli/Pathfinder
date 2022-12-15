#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "IState.h"

class StartState : public IState {
public:
    StartState()
    {
        m_tileType = TileType::Start;
    }
    ~StartState() override = default;
    IState* handleInput(IState* currentState, const sf::Keyboard::Key& input) const override;

};

