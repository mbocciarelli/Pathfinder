//
// Created by Daniel Chiquet on 09/12/2022.
//

#ifndef PATHFINDER_TEXTFIELD_H
#define PATHFINDER_TEXTFIELD_H


#include "InterfaceContentNode.h"

namespace InputManager {
    class TextField : public InterfaceContentNode {
    public:
        std::string text;


        TextField(){
            text = "10";
            _contentType = ContentType(TEXTFIELD);
            _sprite = new sf::Sprite();
            // set write rect sprite
            _sprite-> setTextureRect(sf::IntRect(50,50,100,50));
        }
        ~TextField();





    };

}

#endif //PATHFINDER_TEXTFIELD_H
