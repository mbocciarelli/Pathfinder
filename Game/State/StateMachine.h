#pragma once
#include "Scene.hpp"
#include "IState.h"

class StateMachine {
public:
    IState mCurrentState = new DefaultState();

    StateMachine() = default;
    StateMachine(IState* state) : mCurrentState(state) {}
    ~StateMachine() = default;

    void update(Scene& scene) {
        if (mCurrentState) {
            mCurrentState->update(scene);
        }
    }

    void handleInput(Scene& scene, const Input& input) {
        if (mCurrentState) {
            mCurrentState->handleInput(scene, input);
        }
    }

    void setState(IState* state) {
        mCurrentState = state;
    }
};

