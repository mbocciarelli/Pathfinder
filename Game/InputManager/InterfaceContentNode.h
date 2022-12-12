#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../Composite/Composite.h"
//#include "ContentType.h"

namespace InputManager {
    enum ContentType{
        BUTTON,
        TEXTFIELD,
        TEXT,
        SPRITE
    };

    class InterfaceContentNode : public Composite<InterfaceContentNode>{
    public:
        std::string _name;
        sf::Sprite *_sprite;
        ContentType _contentType;
        // IState<InterfaceContentNode> _state;
        bool _isLeaf;
        bool _isVisibled;
        bool _isClickable;
        std::function<void()> _callback;



        InterfaceContentNode() {}
        ~InterfaceContentNode() {}


        const std::string &getName() const;

        void setName(const std::string &name);

        sf::Sprite *getSprite() const;

        void setSprite(sf::Sprite *sprite);

        bool isIsLeaf() const;

        void setIsLeaf(bool isLeaf);

        ContentType getContentType() const;

        void setContentType(ContentType contentType);

        bool isIsVisibled() const;

        void setIsVisibled(bool isVisibled);

        bool isIsClickable() const;

        void setIsClickable(bool isClickable);

        std::function<void()> getCallback() const;

        void setCallback(std::function<void()> callback);

        void Draw(sf::RenderWindow &window);

        void DrawEachChild(sf::RenderWindow &window);


    };
} // InputManager
