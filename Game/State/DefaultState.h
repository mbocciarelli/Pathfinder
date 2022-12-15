#pragma once

#include "State/IState.h"

class DefaultState : public IState {
public:
    DefaultState() = default;
    ~DefaultState() override = default;

    IState* handleInput(Scene& Scene, const Input& input) const override;
};