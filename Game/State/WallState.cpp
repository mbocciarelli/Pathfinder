#include "WallState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "StartState.h"
#include "PortalState.h"


IState* WallState::handleInput(IState* currentState, const sf::Keyboard::Key& input) const {
    switch (input) {
        case sf::Keyboard::S:
            return new StartState();
        case sf::Keyboard::E:
            return new EndState();
        case sf::Keyboard::P:
            return new PortalState();
        case sf::Keyboard::W:
            return currentState;
        case sf::Keyboard::G:
            return new DefaultState();
        default:
            return currentState;
    }
}
