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
	float rotation;
	Color colour;
} Entity_polar;

Entity_base entity_polar_to_base(Entity_polar *);
// TODO: This is helpful for saving
//Entity_alt entity_base_to_polar(Entity_base *);
