#include "StartState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "WallState.h"
#include "PortalState.h"


IState *StartState::handleInput(IState* currentState, const sf::Keyboard::Key& input) const {
    switch (input) {
        case sf::Keyboard::S:
            return currentState;
        case sf::Keyboard::E:
            return new EndState();
        case sf::Keyboard::P:
            return new PortalState();
        case sf::Keyboard::W:
            return new WallState();
        case sf::Keyboard::G:
            return new DefaultState();
        default:
            return currentState;
    }
}
