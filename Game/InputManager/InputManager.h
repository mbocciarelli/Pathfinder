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

    public:

        InputManager() {
            _tree = new InterfaceContentTree();
        }

        ~InputManager() {}

        void SetCurrentSelectedNode(InterfaceContentRoot node) {
            _tree->setCurrentNode(&node);
        }

        InterfaceContentRoot GetCurrentSelectedNode() {
            return *_tree->getCurrentNode();
        }

        void SetTree(InterfaceContentTree *tree) {
            _tree = tree;
        }

        InterfaceContentTree *GetTree() {
            return _tree;
        }

        void AddNode(InterfaceContentRoot *node) {
            _tree->addNode(node);
        }

        void RemoveNode(InterfaceContentRoot *node) {
            _tree->removeNode(node);
        }

        // get callback function
        std::function<void(sf::Event)> GetCallback() {
            return _tree->getCurrentNode()->_callback;
        }

        // Draw
        void Draw(sf::RenderWindow &window){
            InterfaceContentRoot *root = _tree->getRoot();
            // TODO here compile error
            root->DrawEachChild(window);
        }

        void keyPressed(sf::Event event) {
            InterfaceContentRoot *current = _tree->getCurrentNode();
            switch (current->_contentType) {
                case ContentType::TEXTFIELD:
                    current->getCallback()(event);
                    break;
                default:
                    break;
            }
        }

        void mousePressed(sf::Event event) {
            // if pressed on sprite of visible nodes
            InterfaceContentRoot *treeRoot = _tree->getRoot();
            InterfaceContentRoot *current = _tree->getCurrentNode();
            InterfaceContentRoot *clickedNode = treeRoot->getClickedNode(event);    /* FIXME:   Game/InputManager/InterfaceContentNode.h:142:17: error: no matching function for call to object of type 'InputManager::InterfaceContentNode<InputManager::InterfaceContentRoot>::TraverseCallbackType' (aka 'function<void (InputManager::InterfaceContentRoot *)>')
                                                                                                fn(this);*/



            switch (clickedNode->_contentType) {
                case ContentType::BUTTON:
                    current->getCallback()(event);
                    break;
                default:
                    break;
            }
        }



    };
}
