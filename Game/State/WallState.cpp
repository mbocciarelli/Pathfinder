#include "WallState.h"
#include "GroundState.h"
#include "RunState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "StartState.h"


IState* WallState::handleInput(Scene& scene, const Input& input) const {
    switch (input) {
        case Input::Start:
            return new StartState();
        case Input::End:
            return new EndState();
        case Input::Ground:
            return new GroundState();
        case Input::Wall:
            return new DefaultState();
        case Input::Run:
            return new RunState();
        default:
            return nullptr;
    }
}
