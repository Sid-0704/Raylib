#include <iostream>
#include "grid.h"
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


vector<Color> Grid::getCellColours(){
    Color first_colour = {10,20,30,45};
    Color second_colour = {10,20,30,45};
    Color third_colour = {10,20,30,45};
    Color fourth_colour = {10,20,30,45};
    Color fifth_colour = {10,20,30,45};
    Color sixth_colour = {10,20,30,45};
    Color seventh_colour = {10,20,30,45};
    Color eighth_colour = {10,20,30,45};
// all 8 colours defined above

    return {first_colour, second_colour, third_colour, fourth_colour, fifth_colour, sixth_colour, seventh_colour, eighth_colour};
}


void Grid::draw(){

    for(int rows=0; rows<numRows; rows++){

        for(int cols=0; cols<numCols; cols++){
            int cellValue = grid[rows][cols];
        }

    }


}