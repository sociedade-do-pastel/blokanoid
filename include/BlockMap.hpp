#pragma once

#include <iostream>
#include <raylib.h>
#include <vector>
#include "Block.hpp"
#include "Components.hpp"
#include "Manager.hpp"

#define GAP 2

class BlockMap
{
public:
    static void mountMap(Manager* m, std::vector<std::vector<char>> v,
                         Vector2 pos, Vector2 size)
    {
        int r      = 10;
        int c      = 12;
        int blockW = size.x / c;
        int blockH = size.y / r;

        v.clear();

        for (int i{0}; i < 10; ++i) {
            std::vector<char> temp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            if (i < 6) {
                for (int j{0}; j < 12; ++j) {
                    if (j < 2 || j > 9) {
                        temp[j] = 0;
                        continue;
                    }

                    temp[j] = GetRandomValue(0, 5);
                }
            }
            v.push_back(temp);
        }

        for (int i{0}; i < r; ++i) {
            for (int j{0}; j < c; ++j) {
                if (v.at(i).at(j) == 0)
                    continue;

                Block::makeEntity(m->addEntity(), pos.x + blockW * j + GAP,
                                  pos.y + blockH * i + GAP, blockW - GAP,
                                  blockH - GAP, v.at(i).at(j));
            }
        }
    }
};
