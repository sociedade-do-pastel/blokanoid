#pragma once

#include <raylib.h>

class Game
{
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height, bool isFullscreen,
              int targetFPS);
    void runLoop();
    void shutdown();

private:
    void processInput();
    void update();
    void draw();
};
