#pragma once

#include <string>
#include "Manager.hpp"

class GameState
{
public:
    GameState()
    {
    }
    virtual ~GameState()
    {
    }

    virtual void init()        = 0;
    virtual void update()      = 0;
    virtual void loadState()   = 0;
    virtual void unloadState() = 0;
    virtual void draw()        = 0;

    virtual GameState* getNextGameState() = 0;

	static bool stateChanged;
	
protected:
    std::string m_name{};
    Manager* m_manager{nullptr};
};
