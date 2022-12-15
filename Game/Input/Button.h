#pragma once

#include <SFML/Graphics.hpp>
#include "../Component/Sprite.hpp"
#include "../State/IState.h"

class Button {
public:
    Button (sf::Vector2f location, Input input, std::string path);
    bool checkClick (sf::Vector2i);
    Sprite* getSprite();
    void setInput(Input input);
    Input getInput();
private:
    Sprite normal;
    Sprite clicked;
    Input mInput;

};

Button::Button(sf::Vector2f location, Input input, std::string path) {
    this->normal.CreateSprite(path);
    mInput = input;
    this->normal.GetSprite()->setPosition(location);
}

bool Button::checkClick(sf::Vector2i mousePos) {
    if (this->normal.GetSprite()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        return true;
    }
}

Sprite* Button::getSprite() {
    return &this->normal;
}

void Button::setInput(Input input) {
    this->mInput = input;
}

Input Button::getInput() {
    return this->mInput;
}




