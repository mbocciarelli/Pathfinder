#include "RunState.h"
#include "WallState.h"
#include "GroundState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "StartState.h"



IState* RunState::handleInput(Scene& scene, const Input& input) const {
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
            return new DefaultState();
        default:
            return nullptr;
    }
}
