#include "raylib.h"
#include "raymath.h"
#include "../include/player.h"
#include "../include/world_info.h"
#include "../include/mathh.h"

int main() {
  //const int screenWidth = 800;
  //const int screenHeight = 600;
  //const int sceneWidth = screenWidth * 10;
  //const int sceneHeight = screenHeight * 10;

  InitWindow(screenWidth, screenHeight, "raylib basic window");
  SetTargetFPS(60);

  // triangle starting position
  Entity_base player;
  player.v1 = (Vector2) {20, (float)screenHeight/3.0f };
  player.v2 = (Vector2) {player.v1.x, player.v1.y + 20.0f};
  player.v3 = (Vector2) {player.v1.x + 20.0f, player.v1.y + 10.0f};
  float angle = 0;


  while (!WindowShouldClose()) {
    BeginDrawing();
    //rotation(player, angle + 1);
    angle = (float) (((int) angle + 1) % 360);
    rotation(&player, angle);
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("angle: %02.02f", angle), 20, 20, 20, BLACK);
    DrawText(TextFormat("x: %02.02f", player.v1), 20, 40, 20, BLACK);
    DrawTriangle(player.v1, player.v2, player.v3, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}