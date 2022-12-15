#include "WallState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "StartState.h"
#include "PortalState.h"


IState* WallState::handleInput(const Input& input) const {
    switch (input) 
    {
        case Input::Start:
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
