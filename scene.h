#pragma once

#include "Vector_2D.h"

#include <map>
#include <string>
#include <vector>

#include <SDL.h>

class game_object;

class scene
{
public:
	scene(std::string id);
	~scene();

	virtual void update(SDL_Window* window) = 0;

	game_object* get_game_object(std::string id);
	std::vector<game_object*> get_game_objects();

	Vector_2D camera_translation();

	std::string id();

	Uint8 _red = 255;
	Uint8 _green = 0;
	Uint8 _blue = 255;

protected:
	std::map<std::string, game_object*> _game_objects;
	std::string                         _id;
	Vector_2D                           _camera_translation;


};