

#include "InterfaceContentNode.h"


namespace InputManager {

    template<typename Derived>
    const std::string &InterfaceContentNode<Derived>::getName() const {
        return _name;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setName(const std::string &name) {
        _name = name;
    }

    template<typename Derived>
    sf::Sprite *InterfaceContentNode<Derived>::getSprite() const {
        return _sprite;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setSprite(sf::Sprite *sprite) {
        _sprite = sprite;
    }

    template<typename Derived>
    ContentType InterfaceContentNode<Derived>::getContentType() const {
        return _contentType;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setContentType(ContentType contentType) {
        _contentType = contentType;
    }

    template<typename Derived>
    bool InterfaceContentNode<Derived>::isVisible() const {
        return _visible;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setVisible(bool visibled) {
        _visible = visibled;
    }

    template<typename Derived>
    bool InterfaceContentNode<Derived>::isClickable() const {
        return _clickable;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setClickable(bool isClickable) {
        _clickable = isClickable;
    }

    template<typename Derived>
    std::function<void(sf::Event)> InterfaceContentNode<Derived>::getCallback() const {
        return _callback;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setCallback(std::function<void(sf::Event)> callback) {
        _callback = callback;
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::Draw(sf::RenderWindow &window) {
        if(_visible) {
            window.draw(*_sprite);
        }
    }



    template<typename Derived>
    void InterfaceContentNode<Derived>::DrawEachChild(sf::RenderWindow &window) {
        // !visibled don't draw node and his children
        this->traverseVisible([&window](InterfaceContentNode<Derived> *node) {
            if(node->isVisibled()) {
                node->Draw(window);
            }
        });
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setSize(WidthHeight size) {
        _size = size;
    }

    template<typename Derived>
    WidthHeight InterfaceContentNode<Derived>::getSize() const {
        return WidthHeight();
    }

    template<typename Derived>
    nodePosition InterfaceContentNode<Derived>::getAbsolutePosition() {
        if (m_parent == nullptr) {
            return this->_position;
        } else {
            return this->_position + m_parent->getAbsolutePosition();
        }
    }

    template<typename Derived>
    void InterfaceContentNode<Derived>::setRelativePosition(nodePosition position) {
        _position = position;
        nodePosition absolutePosition = getAbsolutePosition();
        _sprite->setPosition(absolutePosition.x, absolutePosition.y);
    }

    template<typename Derived>
    nodePosition InterfaceContentNode<Derived>::getRelativePosition() {
        return nodePosition();
    }
} // InputManager
