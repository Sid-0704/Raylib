#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"


int main(){

    Color darkBlue = {44,44,127,60}; // Color is a struct here
    InitWindow(800, 800, "Raylib Sample");
    SetTargetFPS(60);


    Grid grid = Grid();

    LBlock block = LBlock();


    grid.print();


    while(!WindowShouldClose()){

        BeginDrawing();
 
        ClearBackground(darkBlue);

        grid.draw();
        block.Draw();

        EndDrawing();


    }

    
        CloseWindow();       
    return 0;
}