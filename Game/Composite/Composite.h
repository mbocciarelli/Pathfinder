#pragma once

#include <SFML/Graphics.hpp>
#include <string>
//#include "ContentType.h"


template<typename Derived>
class Composite
{
public:
    Composite(Derived* parent = nullptr) : m_parent(nullptr)
    {
        static_cast<Derived*>(this)->setParent(parent);
    }

    virtual ~Composite()
    {
        setParent(nullptr);

        auto sonsCpy = m_sons;
        for(auto& son : sonsCpy)
            delete son;
    }

    void setParent(Composite<Derived>* newParent)
    {
        if (m_parent)
            m_parent->_remove(this);

        m_parent = newParent;

        if (m_parent)
            m_parent->_add(this);
    }

    void add(Composite<Derived>* newChild)
    {
        newChild->setParent(this);
    }

    using ChildrenListType = std::vector<Composite<Derived>*>;
    const ChildrenListType& getChildren()
    {
        return m_sons;
    }

    using TraverseCallbackType = std::function<void(Derived*)>;
    void traverse(TraverseCallbackType fn)
    {
        for(auto& son : m_sons)
            son->traverse(fn);

        fn(this);
    }

protected:
    void _add(Composite* newChild)
    {
        m_sons.push_back(newChild);
    }

    void _remove(Composite* child)
    {
        auto it = std::find(m_sons.begin(), m_sons.end(), child);
        if (it == m_sons.end())
            throw std::runtime_error("Son could not be found.");

        m_sons.erase(it);
    }

private:
    ChildrenListType m_sons;
    Composite<Derived>* m_parent;
};