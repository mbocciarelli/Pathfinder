#pragma once

#include "Scene.hpp"

enum class Input {
    Start = 0,
    End,
    Ground,
    Wall,
    Run
};

class IState {
public:
    virtual ~IState() = default;
    virtual IState* handleInput(Scene& Scene, const Input& input) const = 0;
};
