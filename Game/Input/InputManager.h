#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "../State/IState.h"
#include "../State/DefaultState.h"

class InputManager {
private:
    IState* m_state;

public:

    InputManager()
    {
        m_state = new DefaultState();
    }
    ~InputManager() = default;

    void handleInput(const sf::Keyboard::Key input);

    IState* getCurrentState() const;

};

