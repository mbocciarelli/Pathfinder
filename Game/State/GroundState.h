#pragma once

#include "IState.h"
#include "../Scene.hpp"

class GroundState :public IState {
private:
    TileType* m_tileType;
public:
    GroundState() {
        m_tileType = new TileType(TileType::Ground);
    }
    ~GroundState() = default;

    IState* handleInput(const Input& input) const override;

};

