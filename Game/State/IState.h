#pragma once

#include "Scene.hpp"
#include "../Scene.hpp"

enum class Input {
    Start = 0,
    End,
    Ground,
    Wall,
    Run,
    TileMap
};

class IState {
public:
    virtual ~IState() = default;
    virtual IState* handleInput(Scene& scene, const Input& input) const = 0;
};
