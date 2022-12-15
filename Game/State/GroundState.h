#pragma once

#include "IState.h"
#include "Scene.hpp"

class GroundState :public IState {
public:
    GroundState() = default;
    ~GroundState() = default;

    IState* handleInput(Scene& Scene, const Input& input) const override;


};

