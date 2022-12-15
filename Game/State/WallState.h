#include "IState.h"
#include "../Scene.hpp"

class WallState : public IState {
public:
    WallState() = default;
    ~WallState() override = default;

    IState* handleInput(const Input& input) const override;

    void UpdateTile(Tile& tile) const override;
};
