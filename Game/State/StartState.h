#pragma once

#include "IState.h"
#include "../Scene.hpp"

class StartState : public IState {
public:
    StartState() = default;
    IState* handleInput(const Input& input) const override;

    void UpdateTile(Tile& tile) const override;
};

