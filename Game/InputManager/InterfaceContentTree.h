#pragma once

#include "SFML/Graphics.hpp"
#include "InterfaceContentNode.h"
#include <array>



namespace InputManager {
    class InterfaceContentTree {
    protected:
        InterfaceContentRoot *_root;
        InterfaceContentRoot *_currentNode;

    public:
        //bool _visibled;


        InterfaceContentTree() {
            InterfaceContentRoot *root = new InterfaceContentRoot();
            _root = root;
            _currentNode = root;
        }
        ~InterfaceContentTree() {}

        InterfaceContentTree(InterfaceContentRoot *root): _root(root) {
            _currentNode = root;
            //_visibled = true;
        }

        void addNode(InterfaceContentRoot *node) {
            _currentNode->add(node);
        }

        void removeNode(InterfaceContentRoot *node) {
            delete node;
        }

        void setCurrentNode(InterfaceContentRoot *node) {
            _currentNode = node;
        }

        InterfaceContentRoot *getCurrentNode() {
            return _currentNode;
        }

        InterfaceContentRoot *getRoot() {
            return _root;
        }
    };



}
