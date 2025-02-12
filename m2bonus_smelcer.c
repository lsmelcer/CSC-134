#include "raylib.h"
# include <stdlib.h>

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    GameScreen currentScreen = LOGO;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------
    // All our variables
    int player_x = screenWidth/2;
    int player_y = screenHeight/2;
    int speed_x = 0;
    int speed_y = 0;
    int grid_size = 50;
    int grid_columns = screenWidth / grid_size;
    int grid_rows = screenHeight / grid_size;
    int random_column = rand() % grid_columns;
    int random_row = rand() % grid_rows;
    int fruit_x = random_column * grid_size;
    int fruit_y = random_row * grid_size;
    int points = 0;
    
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            switch(currentScreen)
            {
                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("Loading Snake, please wait...", 290, 220, 20, GRAY);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, MAROON);
                    DrawText("SNAKE TITLE SCREEN", 20, 20, 40, GOLD);
                    DrawText("PRESS ENTER or click to start", 120, 220, 20, GOLD);

                } break;
                case GAMEPLAY:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, DARKGREEN);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, SKYBLUE);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, SKYBLUE);
                    
                    
                    
                    // Draw player here
                    /*
                    int player_x = 0;
                    int player_y = 0;
                    int speed_x = 1;
                    int speed_y = 1;
                    */
                    // update position
                    //player_x = player_x + speed_x;
                    //player_y = player_y + speed_y;
                    
                    if (IsKeyPressed (KEY_LEFT)) {
                        if (speed_x != 5) {
                            speed_x = -5;
                            speed_y = 0;
                        } else {
                            speed_x = 5;
                            speed_y = 0;
                        }
                    }
                    if (IsKeyPressed (KEY_RIGHT)) {
                        if (speed_x != -5) {
                            speed_x = 5;
                            speed_y = 0;
                        } else {
                            speed_x = -5;
                            speed_y = 0;
                        }
                    }
                    if (IsKeyPressed (KEY_UP)) {
                        if (speed_y != 5) {
                            speed_y = -5;
                            speed_x = 0;
                        } else {
                            speed_y = 5;
                            speed_x = 0;
                        }
                    }
                    if (IsKeyPressed (KEY_DOWN)) {
                        if (speed_y != -5) {
                            speed_y = 5;
                            speed_x = 0;
                        } else {
                            speed_y = -5;
                            speed_x = 0;
                        }
                    }
                    player_x = player_x + speed_x;
                    player_y = player_y + speed_y;
                    
                    // wrap around or game end
                    /*
                    if (player_x > screenWidth || player_x < 0) {
                        //player_x = 0;
                        //speed_x = -speed_x;
                        
                    }
                    if (player_y > screenHeight || player_y < 0) {
                        //player_y = 0;
                        //speed_y = -speed_y;
                        
                    }
                    */
                    
                    
                    // draw player
                    DrawRectangle(player_x, player_y, 50, 50, RED);
                    
                    // fruit
                    DrawRectangle(fruit_x, fruit_y, 40, 40, RAYWHITE);
                    
                    if (abs(player_x - fruit_x) < 5) {
                        if (abs(player_y - fruit_y) < 5) {
                            points += 1;
                            grid_columns = screenWidth / grid_size;
                            grid_rows = screenHeight / grid_size;
                            random_column = rand() % grid_columns;
                            random_row = rand() % grid_rows;
                            fruit_x = random_column * grid_size;
                            fruit_y = random_row * grid_size;
                        }
                    }
                    
                    
                   
                    // game end
                    if (player_x > 750 || player_x < 0) {
                        currentScreen = ENDING;
                        speed_x = 0;
                        speed_y = 0;
                        player_x = screenWidth/2;
                        player_y = screenHeight/2;
                    }
                    if (player_y > 400 || player_y < 0) {
                        currentScreen = ENDING;
                        speed_x = 0;
                        speed_y = 0;
                        player_x = screenWidth/2;
                        player_y = screenHeight/2;
                        
                    }
                
                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, MAROON);
                    DrawText("ENDING SCREEN", 20, 20, 40, GOLD);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, GOLD);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

