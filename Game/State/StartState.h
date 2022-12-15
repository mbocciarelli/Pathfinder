#pragma once

#include "IState.h"
#include "Scene.hpp"

class StartState : public IState {
public:
    IState* handleInput(Scene& Scene, const Input& input) const override;
};

