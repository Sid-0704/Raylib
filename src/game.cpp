#include "game.h"
// #include "block.h"

#include <random>

Game::Game(){
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock =getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver =false;

}

Block Game::getRandomBlock(){

    if(blocks.empty()){
        blocks =getAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;

}

std::vector<Block> Game::getAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), ZBlock(), TBlock()};
}

void Game::Draw(){
    grid.draw();
    currentBlock.Draw();
}

void Game::handleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed!=0){
        gameOver=false;
        Reset();
    }

    switch (keyPressed){
        case KEY_LEFT:
            moveBlockLeft();
            break;
        case KEY_RIGHT:   
            moveBlockRight();
            break;
    
        case KEY_DOWN:
            moveBlockDown();
            break;
        
        case KEY_UP:
            rotateBlock();
            break;
    }
}

void Game::moveBlockLeft(){
    if(!gameOver){

        currentBlock.move(0,-1);
        if(isBlockOutside() || blockFits() ==false){
            currentBlock.move(0,1);
        }
    }
}

void Game::moveBlockRight(){
    if(!gameOver){

        currentBlock.move(0,1);
        if(isBlockOutside() || blockFits()==false ){
            currentBlock.move(0,-1);
        }
    }
}

void Game::moveBlockDown(){
    if(!gameOver){

        currentBlock.move(1,0);
        if(isBlockOutside() || blockFits() == false){
            currentBlock.move(-1,0);
            lockTheBlock();
        }
    }
}



bool Game::isBlockOutside(){
    std::vector<Position> tiles = currentBlock.getCellPositions();

    for(Position items : tiles){
        if(grid.isCellOutside(items.row, items.column)){
            return true;
        }    
    }
    return false;
}


void Game::rotateBlock(){
    if(!gameOver){

        currentBlock.rotate();
        if(isBlockOutside() || blockFits()==false){
            currentBlock.undoRotation();
        }
    }

}

bool Game::blockFits(){
    std::vector<Position> tiles =currentBlock.getCellPositions();
    for (Position items: tiles){
        if(grid.isCellEmpty(items.row, items.column) == false ){
            return false;
        }
    }
    return true;
}

void Game::Reset(){
    grid.initialize();
    blocks=getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock =getRandomBlock();

}

void Game::lockTheBlock(){
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles){
        // guard against accidental out-of-bounds writes
        if(!grid.isCellOutside(item.row, item.column)){
            grid.grid[item.row][item.column] = currentBlock.id;
        }
    }

    // Move to next block first, then check if the new current block fits —
    // if it doesn't, the game is over.
    currentBlock = nextBlock;
    nextBlock = getRandomBlock();

    if(blockFits() == false){
        gameOver = true;
    }

    grid.clearFullRows();

}