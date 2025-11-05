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


void Grid::print(){
    for(int rows=0; rows<numRows; rows++){
        
        for(int cols=0; cols<numCols; cols++){
            cout << grid[rows][cols] << " ";
        }
        cout << endl;
    
    }
}





void Grid::draw(){

    for(int rows=0; rows<numRows; rows++){

        for(int cols=0; cols<numCols; cols++){
            int cellValue = grid[rows][cols];

            DrawRectangle((cols*cellSize+1), (rows * cellSize+1) , (cellSize-1) , (cellSize-1) , colours[cellValue] );

        }

    }


}