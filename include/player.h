#pragma once
#include "raylib.h"


// Player (triangle)
typedef struct {
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;
	Color colour;
} Entity_base;


// Alternate implementation
// Polar form
typedef struct {
	Vector2 center;
	Vector2 rotation_dir;
	Color colour;
} Entity_polar;

Entity_base entity_polar_to_base(Entity_polar *);
// TODO: This is helpful for saving
//Entity_alt entity_base_to_polar(Entity_base *);

void draw_entity(Entity_polar *);

void move_to_mouse(Entity_polar *, float);

void look_at_mouse(Entity_polar *, Vector2);