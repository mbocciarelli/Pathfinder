//
// Created by Daniel Chiquet on 09/12/2022.
//

#ifndef PATHFINDER_TEXTFIELD_H
#define PATHFINDER_TEXTFIELD_H


#include "InterfaceContentNode.h"

namespace InputManager {
    class TextField : public InterfaceContentRoot {
    public:
        sf::String textInput;
        sf::Text *_text;


        TextField(){
            _text = new sf::Text("10", sf::Font(), 20);
            textInput = "10";
            _contentType = ContentType(TEXTFIELD);
            _sprite = new sf::Sprite();
            // set write rect sprite
            _sprite-> setTextureRect(sf::IntRect(50,50,100,50));
            _visible = true;
            _callback = [&](sf::Event event) {
                if (event.type == sf::Event::TextEntered) {
                    if (48 <= event.text.unicode && event.text.unicode <= 57 || event.text.unicode == 8) {
                        textInput += event.text.unicode;
                        // if textInput is empty
                        if (textInput.getSize() == 0) {
                            textInput = "0";
                        } else if (textInput.getSize() > 3) {
                            textInput = textInput.substring(0, 3);
                        }
                        _text->setString(textInput);
                    }
                }
            };
        }
        ~TextField() = default;




    };

}

#endif //PATHFINDER_TEXTFIELD_H
