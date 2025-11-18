#pragma once
#include <raylib.h>
#include <vector>
using namespace std;



class Grid{

    public:
        Grid(); // constructor

        int clearFullRows();
        void draw();
        vector<Color> colours;
        void print();
        void initialize();
        int grid[20][10];
        bool isCellOutside(int row, int col);
        bool isCellEmpty(int row, int col);

    private:
        bool isRowFull(int row);
        void clearRow(int row);
        void moveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
};


