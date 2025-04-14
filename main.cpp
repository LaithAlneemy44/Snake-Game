#include <iostream>
#include <unistd.h>
#include "raylib.h"
#include "Utils.hpp"
#include "Snake.hpp"
#include "Apple.hpp"

using namespace std;
using namespace Utils;
int main() {
    const int screen_size = 567;   
    const int snake_size = 25;
    const int grid_size = 20;
    const int spacing = screen_size / (grid_size + 1);
    
    const Vector2 centre = getCentre(screen_size, snake_size);
    const Vector2 top_left = {0, 0};
    const Vector2 top_right = {screen_size - snake_size - 1, 0};
    const Vector2 bottom_left = {0, screen_size - snake_size - 1};
    
    const double move_interval = 0.1;
    double move_time = 0;
    
    SetRandomSeed(time(0));
    Snake snake({centre, snake_size, grid_size}, centre, snake_size, screen_size);
    
    InitWindow(screen_size, screen_size, "Snake Window");
    SetTargetFPS(60);              
    while (!WindowShouldClose()){ 
        BeginDrawing();
        if (!snake.living()) {
            ClearBackground(BLACK);
            DrawRectangleV(top_left, {screen_size, snake_size + 1}, GRAY);
            DrawRectangleV(top_left, {snake_size + 1, screen_size}, GRAY);
            DrawRectangleV(top_right, {snake_size + 1, screen_size}, GRAY);
            DrawRectangleV(bottom_left, {screen_size, snake_size + 1}, GRAY);
            snake.gameOver();
            EndDrawing();
            continue;
        }
        
        const int direction = GetKeyPressed();
        if (direction != 0) {
            snake.buffer(direction);
        }
        
        
        move_time += GetFrameTime();
        if (move_time >= move_interval) {
            move_time = 0;
            if (snake.turned()) {
                snake.turn();
            }
            
            else {
                snake.update();
            }
        }
        
        else {
            snake.draw();
        }
        
        ClearBackground(BLACK);
        DrawRectangleV(top_left, {screen_size, snake_size + 1}, GRAY);
        DrawRectangleV(top_left, {snake_size + 1, screen_size}, GRAY);
        DrawRectangleV(top_right, {snake_size + 1, screen_size}, GRAY);
        DrawRectangleV(bottom_left, {screen_size, snake_size + 1}, GRAY);
        EndDrawing();
    }
    
    CloseWindow();       
}