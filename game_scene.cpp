#include "game_scene.h"
#include "mario.h"
#include "walking_dino.h"
#include "player.h"

game_scene::game_scene()
	: scene("Game")
{
	_red = 120;
	_green = 120;
	_blue = 255;
	/*game_object* man = new mario("Mario");
	_game_objects[man->id()] = man;*/

	game_object* dino_walking = new walking_dino("Dino.Walking");
	_game_objects[dino_walking->id()] = dino_walking;

	game_object* player_walking = new player("Player.Walking");
	_game_objects[player_walking->id()] = player_walking;
}

game_scene::~game_scene()
{
}

void game_scene::update(SDL_Window* _window)
{
	game_object* player_walking = get_game_object("Player.Walking");

	int w, h;
	SDL_GetWindowSize(_window, &w, &h);

	_camera_translation = Vector_2D(-w / 2.f + player_walking->width() / 2.f, -h / 2.f + player_walking->height() / 2.f) + player_walking->translation();
}