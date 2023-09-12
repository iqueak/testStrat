//
// Created by bohdan.yurov on 04.09.2023.
//

//libs
#include <iostream>
#include "string"
//vendor
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION


//game
#include "Client/GuiController.h"




using namespace std;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

enum Scene{
    MAIN_MENU,
    GAME
};

int main(void)
{



    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Test strategy");

    ToggleFullscreen();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // GAME Init
    Scene CurrentScene = Scene::MAIN_MENU;


    GuiController::AddButton("btn1",[](){
        cout << "BTN1";
    });

    GuiController::AddButton("btn2",[](){
        cout << "BTN2";
    },100);


    //--------------------------------------------------------------------------------------

    try {
        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            // Update
            //----------------------------------------------------------------------------------
            // TODO: Update your variables here
            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            if (CurrentScene == Scene::MAIN_MENU) {
                ClearBackground(RAYWHITE);
                DrawText("CURRENT SCENE: MENU", 190, 200, 20, LIGHTGRAY);

                if ( GuiButton( Rectangle{ 20, 40, 70, 30 }, "GO TO GAME" ) ){
                    CurrentScene=Scene::GAME;
                }

                GuiController::Draw();

            }
            if (CurrentScene == Scene::GAME) {
                ClearBackground(GRAY);
                DrawText("CURRENT SCENE: GAME", 190, 200, 20, LIGHTGRAY);

                if ( GuiButton( Rectangle{ 50, 20, 70, 30 }, "GO TO MENU" ) ){
                    CurrentScene=Scene::MAIN_MENU;
                }
            }

            EndDrawing();
            //----------------------------------------------------------------------------------
        }

        // Должно выводить ошибки во время выполнения, иначе фиксить О-о
    } catch (std::runtime_error &e) {
        // Print errors
        std::cout << e.what();
        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

    }
    return 0;
}
