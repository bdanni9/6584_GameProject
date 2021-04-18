
#include "menu_scene.h"
#include "menu_scene.h"
#include "mario.h"
#include "walking_dino.h"
#include "player.h"
#include"logo.h"

menu_scene::menu_scene()
	: scene("Menu")
{
	 _red = 0;
	 _blue = 0;
	 _green = 0;


	/*game_object* title = new logo("Logo");
	_game_objects[title->id()] = title;*/
	 
	/*game_object* _mario = new mario("Mario");
	_game_objects[_mario->id()] = _mario;*/

	game_object* _logo = new logo("Logo");
	_game_objects[_logo->id()] = _logo;

	/*game_object* dino_walking = new walking_dino("Dino.Walking");
	_game_objects[dino_walking->id()] = dino_walking;*/

	game_object* player_walking = new player("Player.Walking");
	_game_objects[player_walking->id()] = player_walking;
}

menu_scene::~menu_scene()
{
}

void menu_scene::update(SDL_Window* _window)
{

	/*game_object* player_walking = get_game_object("Player.Walking");

	int w, h;
	SDL_GetWindowSize(_window, &w, &h);

	_camera_translation = Vector_2D(-w / 2.f + player_walking->width() / 2.f, -h / 2.f + player_walking->height() / 2.f) + player_walking->translation();*/
}