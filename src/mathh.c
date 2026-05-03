#include "raylib.h"
#include "../include/player.h"
#include "../include/mathh.h"

void rotation(Entity_base *e, float angle) {
	Vector2 center = get_center(*e);

	e->v1 = Vector2Add(Vector2Rotate(Vector2Subtract(e->v1, center), angle), center);
	e->v2 = Vector2Add(Vector2Rotate(Vector2Subtract(e->v2, center), angle), center);
	e->v3 = Vector2Add(Vector2Rotate(Vector2Subtract(e->v3, center), angle), center);
}

Vector2 get_center(Entity_base e) {
	return (Vector2) {
		(e.v1.x + e.v2.x + e.v3.x) / 3.0f,
		(e.v1.y + e.v2.y + e.v3.y) / 3.0f
	};
}
