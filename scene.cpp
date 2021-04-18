#pragma once

#include <iostream>

#include "scene.h"
#include "game_object.h"


scene::scene(std::string id) : _camera_translation(0.f, 0.f)
{
	_id = id;
}
scene::~scene()
{
}

std::vector<game_object*> scene::get_game_objects()
{
	std::vector<game_object*> game_objects;

	for (auto key_value : _game_objects)
	{
		game_objects.push_back(key_value.second);
	}

	return game_objects;
}


game_object* scene::get_game_object(std::string id)
{
	if (_game_objects.find(id) == _game_objects.end())
	{
		std::cout << "Attempted to find a game object that does not exist. ID: " << id << std::endl;
		exit(1);
	}

	return _game_objects[id];
}

Vector_2D scene::camera_translation()
{
	return _camera_translation;
}

std::string scene::id()
{
	return _id;
}