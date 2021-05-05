
#include "menu_scene.h"
#include "menu_scene.h"
#include "mario.h"
#include "walking_dino.h"
#include "player.h"
#include"logo.h"
#include"ground.h"
#include"text.h"
#include"flymonster.h"
#include"blinking_text.h"

menu_scene::menu_scene()
	: scene("Menu")
{
	Reset();
}

menu_scene::~menu_scene()
{
}

void menu_scene::Reset()
{
	_game_objects.clear();

	_red = 0;
	_blue = 0;
	_green = 0;


	/*game_object* title = new logo("Logo");
	_game_objects[title->id()] = title;*/

	/*game_object* _mario = new mario("Mario");
	_game_objects[_mario->id()] = _mario;*/

	game_object* _logo = new logo("Logo");
	_game_objects[_logo->id()] = _logo;

	game_object* Tile = new ground("Ground");
	_game_objects[Tile->id()] = Tile;

	game_object* flyingmonster = new flymonster("Texture.Flying.Monster");
	_game_objects[flyingmonster->id()] = flyingmonster;

	/*game_object* dino_walking = new walking_dino("Dino.Walking");
	_game_objects[dino_walking->id()] = dino_walking;*/

	game_object* player_walking = new player("Player.Walking");
	_game_objects[player_walking->id()] = player_walking;

	game_object* Text = new blinking_text("Text.text", Vector_2D(200.f, 200.f));
	_game_objects[Text->id()] = new blinking_text("Text.text", Vector_2D(200.f, 200.f));
}

void menu_scene::update(SDL_Window* _window)
{
	/*SDL_Color text_color;
	text_color.r = 255;
	text_color.g = 255;
	text_color.b = 0;
	text_color.a = 255;

	text _id(renderer, _id.c_str(), text_color, "HEllo There");*/

	/*game_object* player_walking = get_game_object("Player.Walking");

	int w, h;
	SDL_GetWindowSize(_window, &w, &h);

	_camera_translation = Vector_2D(-w / 1.f + player_walking->width() / 1.f, -h / 1.f + player_walking->height() / 1.f) + player_walking->translation();*/
}