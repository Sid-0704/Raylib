#include "raylib.h"
#include "game.h"


int main(){

    Color darkBlue = {44,44,127,60}; // Color is a struct here
    InitWindow(800, 800, "Raylib Sample");
    SetTargetFPS(60);


    Game game = Game();


    while(!WindowShouldClose()){

        game.handleInput();
        BeginDrawing();
        
        ClearBackground(darkBlue);
        game.Draw();


        EndDrawing();


    }

    
        CloseWindow();       
    return 0;
}