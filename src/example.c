#include "raylib.h"
#include "raymath.h"
#include "../include/player.h"
#include "../include/world_info.h"
#include "../include/mathh.h"

int main() {

  InitWindow(screenWidth, screenHeight, "raylib basic window");
  SetTargetFPS(60);

  // triangle starting position
  // Entity_base player;
  // player.v1 = (Vector2) {20, (float)screenHeight/3.0f };
  // player.v2 = (Vector2) {player.v1.x, player.v1.y + 20.0f};
  // player.v3 = (Vector2) {player.v1.x + 20.0f, player.v1.y + 10.0f};

  Entity_polar player;
  player.center = (Vector2) { 100.0f , 100.0f };
  player.rotation_dir = (Vector2) { 0.0f, 0.0f };

  float angle = 0;
  float rangle = 0;

  // mouse position
  Vector2 mouse_position = {-100.0f, -100.0f};

  while (!WindowShouldClose()) {
    //angle = (float) (((int) angle + 1) % 360);
    //rangle = angle * ( PI / 180.0f ) * 0.25;
    // rotation(&player, rangle);
    mouse_position = GetMousePosition();

    // this is for player to move and rotate
    look_at_mouse(&player, mouse_position);
    //rotation(&player);
    move_to_mouse(&player, 2);

    BeginDrawing();

    ClearBackground(RAYWHITE);
    //DrawText(TextFormat("angle: %02.02f", angle), 20, 20, 20, BLACK);
    DrawText(TextFormat("mouse x: %02.02f | mouse y: %02.02f", mouse_position.x, mouse_position.y), 20, 20, 20, BLACK);
    DrawText(TextFormat("player x: %02.02f | player y: %02.02f", player.center.x, player.center.y), 20, 40, 20, BLACK);
    draw_entity(&player);   
    //DrawTriangle(player.v1, player.v2, player.v3, RED);
    EndDrawing();

  }
  CloseWindow();
  return 0;
}