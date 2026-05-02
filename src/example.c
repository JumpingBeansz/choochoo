#include "raylib.h"
#include "../include/player.h"

int main() {
  //const int screenWidth = 800;
  //const int screenHeight = 600;
  //const int sceneWidth = screenWidth * 10;
  //const int sceneHeight = screenHeight * 10;

  InitWindow(screenWidth, screenHeight, "raylib basic window");
  SetTargetFPS(60);

  // triangle starting position
  Vector2 v1 = {20, (float)screenHeight/3.0f };
  Vector2 v2 = {v1.x, v1.y + 20.0f};
  Vector2 v3 = {v1.x + 20.0f, v1.y + 10.0f};


  while (!WindowShouldClose()) {
    BeginDrawing();
    
    ClearBackground(RAYWHITE);
    //DrawText("It works!", 20, 20, 20, BLACK);
    DrawTriangle(v1, v2, v3, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}