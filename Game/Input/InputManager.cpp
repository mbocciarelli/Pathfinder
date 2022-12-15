//
// Created by Daniel Chiquet on 15/12/2022.
//

#include "InputManager.h"
#include "SFML/Window/Keyboard.hpp"

void InputManager::handleInput(const sf::Keyboard::Key input) {
    if (const auto currentState = m_state->handleInput(getCurrentState(), input); currentState != nullptr && m_state != currentState)
    {
        m_state = currentState;
    }
}

IState *InputManager::getCurrentState() const {
    return m_state;
}
