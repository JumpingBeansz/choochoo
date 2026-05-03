#include "raylib.h"
#include "../include/player.h"


// Player is a triangle
// Example player, position is relative but area is the same
// v1 = {0, 0}
// v2 = {0, 20}
// v3 = {10, 10}

Entity_base entity_polar_to_base(Entity_polar * e_polar) {
	Entity_base e;
	e.v1 = (Vector2) { e_polar->center.x - 5.0f, e_polar->center.y - 10.0f};
	e.v2 = (Vector2) { e_polar->center.x - 5.0f, e_polar->center.y + 10.0f};
	e.v3 = (Vector2) { e_polar->center.x + 5.0f, e_polar->center.y};
	e.colour = e_polar->colour;
	return e;
}

// to reverse, we need to know the one vector and find the angle rotated
// Entity_alt entity_polar_to_base(Entity_base * e) 
