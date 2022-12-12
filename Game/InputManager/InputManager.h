#pragma once

#include "InterfaceContentNode.h"
#include "InterfaceContentTree.h"
#include "IState.h"
#include "Button.h"
#include "TextField.h"


namespace InputManager {
    class InputManager {
    protected:
        InterfaceContentTree *_tree;
        using ContentNodeVector = std::vector<InterfaceContentNode *>;
    public:

        InputManager() {}

        ~InputManager() {}

        void SetCurrentSelectedNode(InterfaceContentNode node) {
            _tree->setCurrentNode(&node);
        }

        InterfaceContentNode GetCurrentSelectedNode() {
            return *_tree->getCurrentNode();
        }

        void SetTree(InterfaceContentTree *tree) {
            _tree = tree;
        }

        InterfaceContentTree *GetTree() {
            return _tree;
        }

        void AddNode(InterfaceContentNode *node) {
            _tree->addNode(node);
        }

        void RemoveNode(InterfaceContentNode *node) {
            _tree->removeNode(node);
        }

        // get callback function
        std::function<void()> GetCallback() {
            return _tree->getCurrentNode()->_callback;
        }

        // Draw
        void Draw(sf::RenderWindow &window);
    };
}
