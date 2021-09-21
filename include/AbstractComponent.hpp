#pragma once

#include "Entity.hpp"

// forward declaration
class Entity;

class AbstractComponent
{
public:
    AbstractComponent();
    virtual ~AbstractComponent() = 0;
    virtual void init()          = 0;
    virtual void update()        = 0;

    // getters
    template <typename T> T& getComponent() const;
    Entity* getOwner() const;

    // setters
    void setOwner(Entity* newOwner);

protected:
    Entity* m_owner{nullptr};
};
