#pragma once
#include "grid.h"
#include "blocks.h"


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
        bool gameOver;


    private:
        bool isBlockOutside();
        void lockTheBlock();
        void rotateBlock();
        bool blockFits();
        void Reset();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;




};