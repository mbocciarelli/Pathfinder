#pragma once

#include "State/IState.h"
#include "../Scene.hpp"

class DefaultState : public IState {
private:
    TileType* m_tileType;
public:
    DefaultState() {
        m_tileType = nullptr;
    }
    ~DefaultState() override = default;

    IState* handleInput(const Input& input) const override;

};