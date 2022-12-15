#include "EndState.h"
#include "StartState.h"
#include "DefaultState.h"
#include "RunState.h"
#include "WallState.h"
#include "GroundState.h"


IState *EndState::handleInput(const Input& input) const {
    switch (input) {
        case Input::Start:
            return new StartState();
        case Input::End:
            return new DefaultState();
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

void EndState::UpdateTile(Tile &tile) const {
    tile.SetTileType<TileType::End>();
}
