#include "raylib.h"
#include "raymath.h"
#include "../include/player.h"
#include <math.h>


// Player is a triangle
// Example player, position is relative but area is the same
// v1 = {0, 0}
// v2 = {0, 20}
// v3 = {10, 10}

Entity_base entity_polar_to_base(Entity_polar * e_polar) {
	Entity_base e;

	Vector2 local_v1 = (Vector2) { - 5.0f, - 10.0f};
	Vector2 local_v2 = (Vector2) { - 5.0f, 10.0f};
	Vector2 local_v3 = (Vector2) { 10.0f, 0.0f };
	// todo rotate the vectors according to the rotation;

	float angle = atan2f(e_polar->rotation_dir.y, e_polar->rotation_dir.x);

	e.v1 = Vector2Add(e_polar->center, Vector2Rotate(local_v1, angle));
	e.v2 = Vector2Add(e_polar->center, Vector2Rotate(local_v2, angle));
	e.v3 = Vector2Add(e_polar->center, Vector2Rotate(local_v3, angle));

	e.colour = e_polar->colour;
	return e;
}

// to reverse, we need to know the one vector and find the angle rotated
// Entity_alt entity_polar_to_base(Entity_base * e) 

void draw_entity(Entity_polar * e) {
	Entity_base temp_entity = entity_polar_to_base(e);
	DrawTriangle(temp_entity.v1, temp_entity.v2, temp_entity.v3, RED);
}

// TODO move in the direction of the rotation
void move_to_mouse(Entity_polar * e, float dist) {
	//Vector2 mouse = GetMousePosition();

	e->center.x += e->rotation_dir.x * dist;
	e->center.y += e->rotation_dir.y * dist;
}

void look_at_mouse(Entity_polar * e, Vector2 target) {
	float turn_speed = 0.025f;

	//Vector2 mouse = GetMousePosition();
	Vector2 direction = Vector2Subtract(target, e->center);
	
	// This turns to mouse immediately
	//e->rotation_dir = Vector2Normalize(direction);

	// This turns to the mouse slowly
	float angle_current = atan2f(e->rotation_dir.y, e->rotation_dir.x);
	float angle_target = atan2f(direction.y, direction.x);

	float delta_angle = angle_target - angle_current;

	while (delta_angle > PI) delta_angle -= 2 * PI;
	while (delta_angle < -PI) delta_angle += 2 * PI;


	if (fabsf(delta_angle) < turn_speed) {
		angle_current = angle_target;
	} else {
		angle_current += (delta_angle > 0 ? 1 : -1) * turn_speed;
	}

	e->rotation_dir.x = cosf(angle_current);
	e->rotation_dir.y = sinf(angle_current);
}