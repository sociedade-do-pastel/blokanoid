#pragma once

#include <functional>
#include <raylib.h>
#include <string>
#include "Components.hpp"
#include "Entity.hpp"

class Button
{
public:
    static void makeEntity(Entity* e, int x, int y, int w, int h, float offsetX,
                           float offsetY, Color normal, Color hover,
                           std::string content, std::function<void(Entity*)> f,
                           bool* press = nullptr);
    static bool clickCheckFunc(Entity* e, bool* press, Color normal,
                               Color hover);
};
