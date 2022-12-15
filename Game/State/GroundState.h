#pragma once

#include "IState.h"
#include "../Scene.hpp"

class GroundState :public IState {
public:
    GroundState() = default;
    ~GroundState() = default;

    IState* handleInput(const Input& input) const override;

    void UpdateTile(Tile& tile) const override;

};

