//
// Created by Daniel Chiquet on 15/12/2022.
//

#include "DefaultState.h"
#include "EndState.h"
#include "StartState.h"
#include "WallState.h"
#include "PortalState.h"

IState *PortalState::handleInput(IState* currentState, const sf::Keyboard::Key& input) const {
    switch (input) {
        case sf::Keyboard::S:
            return new StartState();
        case sf::Keyboard::E:
            return new EndState();
        case sf::Keyboard::P:
            return currentState;
        case sf::Keyboard::W:
            return new WallState();
        case sf::Keyboard::G:
            return new DefaultState();
        default:
            return currentState;
    }
}

