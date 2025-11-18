#pragma once
#include "grid.h"
#include "blocks.cpp"


class Game{
    public:
        Game();
        Block getRandomBlock();
        std::vector<Block> getAllBlocks();
        void Draw();
        void handleInput();
        void moveBlockLeft();
        void moveBlockRight();
        void moveBlockDown();
        Grid grid;


    private:
        bool isBlockOutside();
        void lockTheBlock();
        void rotateBlock();
        bool blockFits();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;




};