#pragma once

#include "State/IState.h"

class DefaultState : public IState {
public:
    DefaultState() = default;
    ~DefaultState() override = default;

    IState* handleInput(Scene& scene, const Input& input) const override;
};