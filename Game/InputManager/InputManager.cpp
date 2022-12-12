//
// Created by Daniel Chiquet on 09/12/2022.
//

#include "InputManager.h"

void InputManager::InputManager::Draw(sf::RenderWindow &window) {
    _tree->DrawEachChild(window);
}
