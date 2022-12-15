#pragma once

#include "State/IState.h"
#include "../Scene.hpp"

class DefaultState : public IState {
public:
    ~DefaultState() override = default;

    IState* handleInput(const Input& input) const override;

    void UpdateTile(Tile& tile) const override;
};