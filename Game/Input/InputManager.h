#pragma once
#include "../State/IState.h"
#include "../Scene.hpp"

class InputManager {
private:
    IState* m_state;
public:

    InputManager() = default;
    ~InputManager() = default;

    void handleInput(const Input& input, sf::Vector2f& position);

    IState* getCurrentState() const;
    void setCurrentState(IState* state);

    void updateTile(Tile& tile);

};

