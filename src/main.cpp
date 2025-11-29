#include "raylib.h"
#include "game.h"
#include <iostream>

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
        if(eventTriggered(0.2)){
            game.moveBlockDown();
        }
        static int __frames = 0;
        __frames++;
        if(__frames % 60 == 0){
            std::cout << "frame: " << __frames << std::endl;
        }
        BeginDrawing();
        
        ClearBackground(darkBlue);
        game.Draw();

        EndDrawing();
    }

    
        CloseWindow();       
    return 0;
}