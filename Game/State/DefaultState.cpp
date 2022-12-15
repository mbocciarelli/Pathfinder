#include "DefaultState.h"
#include "StartState.h"
#include "EndState.h"
#include "WallState.h"
#include "PortalState.h"

IState *DefaultState::handleInput(IState* currentState, const sf::Keyboard::Key& input) const {
    switch (input) {
        case sf::Keyboard::S:
            return new StartState();
        case sf::Keyboard::E:
            return new EndState();
        case sf::Keyboard::P:
            return new PortalState();
        case sf::Keyboard::W:
            return new WallState();
        case sf::Keyboard::G:
            return currentState;
        default:
            return currentState;
    }
}

