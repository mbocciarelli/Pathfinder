//
// Created by Daniel Chiquet on 15/12/2022.
//

#include "GroundState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "StartState.h"
#include "RunState.h"
#include "WallState.h"

IState *GroundState::handleInput(const Input &input) const {
    switch (input) {
        case Input::Start:
            return new StartState();
        case Input::End:
            return new EndState();
        case Input::Ground:
            return new DefaultState();
        case Input::Wall:
            return new WallState();
        case Input::Run:
            return new RunState();
        default:
            return nullptr;
    }
}

