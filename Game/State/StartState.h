#pragma once

#include "IState.h"
#include "../Scene.hpp"

class StartState : public IState {
public:
    StartState() = default;
    IState* handleInput(Scene& scene, const Input& input) const override;
};

