#pragma once

#include "InterfaceContentNode.h"
#include "IState.h"


namespace InputManager{

    class Button : public InterfaceContentNode {
    protected:

    public:
        Button() {
            _contentType = ContentType::BUTTON;
        }

        Button(sf::Sprite *sprite, std::function<void()> callback) {
            _contentType = ContentType::BUTTON;
            _sprite = sprite;
            //_position = position;
            _callback = callback;
        }
        ~Button() {}
    };
}