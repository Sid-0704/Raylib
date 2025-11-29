#include <iostream>
#include "grid.h"
#include "colors.h"
using namespace std;
    


Grid::Grid(){

    numRows =20;
    numCols=10;
    cellSize =30;

    initialize();
    colours = getCellColours();

}


void Grid::initialize(){

    for(int row=0; row<numRows; row++){

        for(int cols=0; cols<numCols; cols++){
            grid[row][cols] = 0; // Initializing all rows and cols to 0 
        }
    }
}

bool Grid::isCellOutside(int row, int col){

    if(row>=0 && row<numRows &&col>=0 && col<numCols){
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int col){
    // Treat any cell outside the grid as non-empty to prevent out-of-bounds access
    if(isCellOutside(row, col)){
        return false;
    }
    if(grid[row][col] == 0){
        return true;
    }
    return false;
}

bool Grid::isRowFull(int row){
    for(int col=0; col<numCols; col++){
        if(grid[row][col] ==0){
            return false;
        }
    }
        return true;   
}

void Grid::clearRow(int row){
    for(int col=0; col<numCols; col++){
        grid[row][col] =0;
    }
}

void Grid::moveRowDown(int row, int numRows){
    for(int col=0; col<numCols; col++){
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

void Grid::print(){
    for(int rows=0; rows<numRows; rows++){
        
        for(int cols=0; cols<numCols; cols++){
            cout << grid[rows][cols] << " ";
        }
        cout << endl;
    
    }
}

int Grid::clearFullRows(){
    int completed=0;
    for(int row=numRows-1; row>=0; row--){
        if(isRowFull(row)){
            clearRow(row);
            completed++;
        }
        else if(completed>0){
            moveRowDown(row,completed);
        }
    }
    return completed;
}

void Grid::draw()
{

    for(int rows=0; rows<numRows; rows++){

        for(int cols=0; cols<numCols; cols++){
            int cellValue = grid[rows][cols];

            DrawRectangle((cols*cellSize+1), (rows * cellSize+1) , (cellSize-1) , (cellSize-1) , colours[cellValue] );

        }
    }
}