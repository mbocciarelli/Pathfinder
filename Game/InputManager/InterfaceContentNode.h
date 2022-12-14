#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace InputManager {
    enum ContentType{
        BUTTON,
        TEXTFIELD,
        TEXT,
        SPRITE,
        CONTENTBLOCK,
        MAP,
        MAPTILE
    };
    struct nodePosition{
        float x;
        float y;

        nodePosition(float x, float y) {
            this->x = x;
            this->y = y;
        }

        nodePosition() {
            this->x = 0;
            this->y = 0;
        }

        nodePosition operator+(const nodePosition& other) {
            return nodePosition(this->x + other.x, this->y + other.y);
        }

        nodePosition operator-(const nodePosition& other) {
            return nodePosition(this->x - other.x, this->y - other.y);
        }
    };

    struct WidthHeight{
        float width;
        float height;

        WidthHeight(float width, float height) {
            this->width = width;
            this->height = height;
        }

        WidthHeight() {
            this->width = 0;
            this->height = 0;
        }
    };

    template<typename Derived>
    class InterfaceContentNode{

    public:
        std::string _name;
        bool _visible;
        bool _clickable;
        nodePosition _position;
        WidthHeight _size;
        sf::Sprite *_sprite;
        ContentType _contentType;
        // IState<InterfaceContentNode> _state;
        // void(event)
        std::function<void(sf::Event)> _callback;


        InterfaceContentNode(Derived* parent = nullptr) : m_parent(nullptr)
        {
            static_cast<Derived*>(this)->setParent(parent);
        }

        virtual ~InterfaceContentNode()
        {
            setParent(nullptr);

            auto sonsCpy = m_sons;
            for(auto& son : sonsCpy)
                delete son;
        }

        void setParent(InterfaceContentNode<Derived>* newParent)
        {
            if (m_parent)
                m_parent->_remove(this);

            m_parent = newParent;

            if (m_parent)
                m_parent->_add(this);
        }

        void add(InterfaceContentNode<Derived>* newChild)
        {
            newChild->setParent(this);
        }

        using ChildrenListType = std::vector<InterfaceContentNode<Derived>*>;
        const ChildrenListType& getChildren()
        {
            return m_sons;
        }

        using TraverseCallbackType = std::function<void(Derived*)>;
        // array of contentOptions
        void traverseVisible(TraverseCallbackType fn)
        {
            if (static_cast<Derived*>(this)->isVisible()) {
                for (auto &son: m_sons)
                    son->traverseVisible(fn);

                fn(this);
            }
        }

        void traverse(TraverseCallbackType fn)
        {
            for(auto& son : m_sons)
                son->traverse(fn);

            fn(this);
        }

        void traverseClickable(TraverseCallbackType fn)
        {
            if (static_cast<Derived*>(this)->isClickable()) {
                for (auto &son: m_sons)
                    son->traverseClickable(fn);

                fn(this);
            }
        }

        void traverseClickableVisible(TraverseCallbackType fn)
        {
            if (static_cast<Derived*>(this)->isClickable() && static_cast<Derived*>(this)->isVisible()) {
                for (auto &son: m_sons)
                    son->traverseClickableVisible(fn);

                fn(this);
            }
        }

        Derived* getClickedNode(sf::Event event) {
            Derived* clickedElement = nullptr;
            traverseClickableVisible([&](Derived* node) {
                if (node->isClicked(event)) {
                    clickedElement = node;
                }
            });
            return clickedElement;
        }

        bool isClicked(sf::Event event) {
            nodePosition absolutePosition = this->getAbsolutePosition();
            bool x_test = event.mouseButton.x >= absolutePosition.x && event.mouseButton.x <= absolutePosition.x + this->_size.width;
            bool y_test = event.mouseButton.y >= absolutePosition.y && event.mouseButton.y <= absolutePosition.y + this->_size.height;
            return x_test && y_test;
        }



        const std::string &getName() const;

        void setName(const std::string &name);

        sf::Sprite *getSprite() const;

        void setSprite(sf::Sprite *sprite);

        ContentType getContentType() const;

        void setContentType(ContentType contentType);

        bool isVisible() const;

        void setVisible(bool visibled);

        bool isClickable() const;

        void setClickable(bool isClickable);

        nodePosition getRelativePosition();

        void setRelativePosition(nodePosition position);

        nodePosition getAbsolutePosition();

        std::function<void(sf::Event)> getCallback() const;

        void setCallback(std::function<void(sf::Event)> callback);

        void Draw(sf::RenderWindow &window);

        void DrawEachChild(sf::RenderWindow &window);

        WidthHeight getSize() const;

        void setSize(WidthHeight size);

    protected:
        void _add(InterfaceContentNode* newChild)
        {
            m_sons.push_back(newChild);
        }

        void _remove(InterfaceContentNode* child)
        {
            auto it = std::find(m_sons.begin(), m_sons.end(), child);
            if (it == m_sons.end())
                throw std::runtime_error("Son could not be found.");

            m_sons.erase(it);
        }
    private:
        ChildrenListType m_sons;
        InterfaceContentNode<Derived>* m_parent;
    };

    class InterfaceContentRoot : public InterfaceContentNode<InterfaceContentRoot> {
    public:
        InterfaceContentRoot() : InterfaceContentNode<InterfaceContentRoot>() {
            _visible = true;
        }
        virtual ~InterfaceContentRoot() = default;

    };

} // InputManager
