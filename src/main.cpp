#include "raylib.h"
#include "game.h"

double lastUpdateTime =0;
bool eventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;

    }
    return false;
}


int main(){

    Color darkBlue = {44,44,127,60}; // Color is a struct here
    InitWindow(800, 800, "Raylib Sample");
    SetTargetFPS(60);


    Game game = Game();


    while(!WindowShouldClose()){
                                                              
        game.handleInput();
        if(eventTriggered(0.5)){
            game.moveBlockDown();
        }
        BeginDrawing();
        
        ClearBackground(darkBlue);
        game.Draw();

        EndDrawing();
    }

    
        CloseWindow();       
    return 0;
}