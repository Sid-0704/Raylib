#include "raylib.h"
#include "grid.h"


int main(){

    Color darkBlue = {44,44,127,60}; // Color is a struct here
    InitWindow(800, 800, "Raylib Sample");
    SetTargetFPS(60);


    Grid grid = Grid();

    grid.grid[0][0] = 1;
    grid.grid[2][3] = 6;
    grid.grid[4][3] = 3;


    grid.print();


    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(darkBlue);

        grid.draw();

        EndDrawing();



    }


        CloseWindow();       
    return 0;
}