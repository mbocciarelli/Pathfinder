#pragma once

#include "InterfaceContentNode.h"
#include "IState.h"


namespace InputManager{

    class Button : public InterfaceContentRoot {
    protected:

    public:
        Button() {
            _contentType = ContentType::BUTTON;
        }

        Button(sf::Sprite *sprite, std::function<void(sf::Event)> callback) {
            _contentType = ContentType::BUTTON;
            this->_sprite = sprite;
            //_position = position;
            _callback = callback;
            this->setVisible(true);
        }
        ~Button() = default;
    };
}