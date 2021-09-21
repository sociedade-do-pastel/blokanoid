#pragma once

#include <algorithm>
#include <memory>
#include <typeinfo>
#include <vector>
#include "AbstractComponent.hpp"

class AbstractComponent;
class Entity
{
public:
    enum class State
    {
        Active,
        Paused,
        Dead
    };

    Entity();
    ~Entity();

    void init();
    void update();

    template <typename T, typename... TArgs> void addComponent(TArgs... fArgs)
    {
        if (getComponent<T>() != nullptr)
            return;
		
        T* comp = new T(fArgs...);
        m_components.emplace_back(comp);
        comp->setOwner(this);
        comp->init();
    }

    void removeComponent(AbstractComponent* comp);

    // getters
    State getState() const;

    template <typename T> T* getComponent() const
    {
        for (auto& c : m_components) {
            if (typeid(*c).name() == typeid(T).name())
                return static_cast<T*>(c.get());
        }

        return nullptr;
    }

    // setters
    void setState(State s);

private:
    std::vector<std::unique_ptr<AbstractComponent>> m_components{};
    State m_state{State::Paused};
};
