#include "raylib.h"
#include "../include/player.h"
#include "../include/mathh.h"

void rotation(Entity_polar *e_polar) {
	//Vector2 center = get_center(*e);
	Entity_base e = entity_polar_to_base(e_polar);

}

Vector2 get_center(Entity_base e) {
	return (Vector2) {
		(e.v1.x + e.v2.x + e.v3.x) / 3.0f,
		(e.v1.y + e.v2.y + e.v3.y) / 3.0f
	};
}
