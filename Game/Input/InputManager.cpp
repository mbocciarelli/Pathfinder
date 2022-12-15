//
// Created by Daniel Chiquet on 15/12/2022.
//

#include "InputManager.h"

IState *InputManager::handleInput(const Input &input) const {
    if (const auto currentState = m_state->handleInput(*this, input); currentState != nullptr && m_state != currentState)
    {
        setCurrentState(currentState);
    }
}

IState *InputManager::getCurrentState() const {
    return m_state;
}

void InputManager::setCurrentState(IState *state) {
    delete m_state;
    m_state = state;
}
