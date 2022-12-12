#pragma once

#include "SFML/Graphics.hpp"
#include "InterfaceContentNode.h"
#include <array>



namespace InputManager {
    class InterfaceContentTree {
    protected:
        InterfaceContentNode *_root;
        InterfaceContentNode *_currentNode;

    public:
        //bool _isVisibled;


        InterfaceContentTree() {}
        ~InterfaceContentTree() {}

        InterfaceContentTree(InterfaceContentNode *root): _root(root) {
            _currentNode = root;
            //_isVisibled = true;
        }

        void addNode(InterfaceContentNode *node) {
            _currentNode->add(node);
        }

        void removeNode(InterfaceContentNode *node) {
            delete node;
        }

        void setCurrentNode(InterfaceContentNode *node) {
            _currentNode = node;
        }

        InterfaceContentNode *getCurrentNode() {
            return _currentNode;
        }


        void traverse(InterfaceContentNode::TraverseCallbackType fn) {
            _root->traverse(fn);
        }

        void DrawEachChild(sf::RenderWindow &window) {
            _root->DrawEachChild(window);
        }
    };
}
