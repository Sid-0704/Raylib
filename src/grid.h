#pragma once
#include <raylib.h>
#include <vector>
using namespace std;



class Grid{

    private:
        int numRows;
        int numCols;
        int cellSize;

    public:
        Grid(); // constructor


        void draw();
        vector<Color> colours;
        void print();
        void initialize();
        int grid[20][10];
        bool isCellOutside(int row, int col);



};


