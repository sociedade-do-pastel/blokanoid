#pragma once

#include <iostream>
#include <vector>
#include "Block.hpp"
#include "Components.hpp"
#include "Manager.hpp"

class BlockMap
{
public:
    static void mountMap(Manager* m, std::vector<std::vector<int>> v,
                         Vector2 pos, Vector2 size)
    {
        int r      = v.size();
        int c      = v.at(0).size();
        int blockW = size.x / c;
        int blockH = size.y / r;

        for (int i{0}; i < r; ++i) {
            for (int j{0}; j < c; ++j) {
                if (v.at(i).at(j) == 0)
                    continue;

                Block(m->addEntity(), pos.x + blockW * j, pos.y + blockH * i,
                      blockW, blockH, v.at(i).at(j));
            }
        }
    }
};
