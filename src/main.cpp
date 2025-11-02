#include "raylib.h"
#include "grid.h"


int main(){

    Color darkBlue = {44,44,127,60}; // Color is a struct here
    InitWindow(300, 600, "Raylib Sample");
    SetTargetFPS(60);


    Grid grid = Grid();

    grid.print();


    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(darkBlue);

        EndDrawing();



    }


        CloseWindow();       
    return 0;
}