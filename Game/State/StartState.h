#pragma once

#include "IState.h"
#include "../Scene.hpp"

class StartState : public IState {
private:
    TileType* m_tileType;
public:
    StartState() {
        m_tileType = new TileType(TileType::Start);
    }
    ~StartState() override = default;
    IState* handleInput(const Input& input) const override;

};

