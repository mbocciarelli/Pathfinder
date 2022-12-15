//
// Created by Daniel Chiquet on 15/12/2022.
//

#include "InputManager.h"
#include "SFML/Window/Keyboard.hpp"

void InputManager::handleInput(const Input &input, sf::Vector2f& position) {
    if (const auto currentState = m_state->handleInput(input); currentState != nullptr && m_state != currentState)
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

void InputManager::updateTile(Tile &tile) {
    TileType* type = m_state->getTileType();
    tile.SetTileType<type>();
}
