

#include "InterfaceContentNode.h"


namespace InputManager {
    const std::string &InterfaceContentNode::getName() const {
        return _name;
    }

    void InterfaceContentNode::setName(const std::string &name) {
        _name = name;
    }

    sf::Sprite *InterfaceContentNode::getSprite() const {
        return _sprite;
    }

    void InterfaceContentNode::setSprite(sf::Sprite *sprite) {
        _sprite = sprite;
    }

    bool InterfaceContentNode::isIsLeaf() const {
        return _isLeaf;
    }

    void InterfaceContentNode::setIsLeaf(bool isLeaf) {
        _isLeaf = isLeaf;
    }

    ContentType InterfaceContentNode::getContentType() const {
        return _contentType;
    }

    void InterfaceContentNode::setContentType(ContentType contentType) {
        _contentType = contentType;
    }

    bool InterfaceContentNode::isIsVisibled() const {
        return _isVisibled;
    }

    void InterfaceContentNode::setIsVisibled(bool isVisibled) {
        _isVisibled = isVisibled;
    }

    bool InterfaceContentNode::isIsClickable() const {
        return _isClickable;
    }

    void InterfaceContentNode::setIsClickable(bool isClickable) {
        _isClickable = isClickable;
    }

    std::function<void()> InterfaceContentNode::getCallback() const {
        return _callback;
    }

    void InterfaceContentNode::setCallback(std::function<void()> callback) {
        _callback = callback;
    }

    void InterfaceContentNode::Draw(sf::RenderWindow &window) {
        if(_isVisibled) {
            window.draw(*_sprite);
        }

    }



    void InterfaceContentNode::DrawEachChild(sf::RenderWindow &window) {
        std::function<void(InterfaceContentNode *)> lambda;
        lambda = [&window](InterfaceContentNode *node) {
            node->Draw(window);
        };
        this->traverse(lambda);
    }



/*
    void InterfaceContentNode::DrawEachChild(sf::RenderWindow &window) {
        std::function<void (InterfaceContentNode *)> lambda = [&window](InterfaceContentNode *node) {
            node->Draw(window);
        };
        this->traverse(lambda);
    }
*/

} // InputManager
