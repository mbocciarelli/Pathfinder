#include "DefaultState.h"
#include "StartState.h"
#include "EndState.h"
#include "RunState.h"
#include "WallState.h"
#include "GroundState.h"

IState *DefaultState::handleInput(Scene& Scene, const Input &input) const {
    switch (input) {
        case Input::Start:
            return new StartState();
        case Input::End:
            return new EndState();
        case Input::Ground:
            return new GroundState();
        case Input::Wall:
            return new WallState();
        case Input::Run:
            return new RunState();
        default:
            return nullptr;
    }
}