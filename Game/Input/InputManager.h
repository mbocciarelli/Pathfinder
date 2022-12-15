#pragma once
#include "../State/IState.h"
#include "../Scene.hpp"

class InputManager {
private:
    IState* m_state;
public:

    InputManager() = default;
    ~InputManager() = default;

    IState* handleInput(const Input& input) const;

    IState* getCurrentState() const;
    void setCurrentState(IState* state);

    void ExecuteState(const Input& input, Scene& scene) const;
};

