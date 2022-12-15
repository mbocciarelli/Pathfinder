#include "StartState.h"
#include "DefaultState.h"
#include "EndState.h"
#include "RunState.h"
#include "WallState.h"
#include "GroundState.h"


IState *StartState::handleInput(const Input& input) const {

switch (input) {
        case Input::Start:
            return new DefaultState();
        case Input::End:
            return new EndState();
        case Input::Ground:
            return new GroundState();
        case Input::Wall:
            return new WallState();
        case Input::Run:
            return new RunState();
    case Input::TileMap:

        default:
            return nullptr;
    }
}

void StartState::UpdateTile(Tile &tile) const {
    tile.SetTileType<TileType::Start>();
}
