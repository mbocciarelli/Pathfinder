#pragma once

#include "SFML/Graphics.hpp"


namespace InputManager{
    class ButtonManager {
    public:
        ButtonManager() {}
        ~ButtonManager() {}

        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

        sf::Vector2i GetMousePosition(sf::RenderWindow &window);

    };
}
