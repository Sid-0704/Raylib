#include "raylib.h"


int main(){

    InitWindow(800, 800, "Raylib Sample");
    SetTargetFPS(60);

    Color darkBlue = {44,44,127,60};



    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(darkBlue);


        EndDrawing();




    }


        CloseWindow();       
    return 0;
}