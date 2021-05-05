#include "scene_manager.h"
#include<iostream>

scene_manager::scene_manager()
{
	_current_scene = nullptr;
}

scene* scene_manager::current_scene()
{

	return _current_scene;
}

void scene_manager::set_current_scene(std::string id)
{
	if (_scenes.find(id) == _scenes.end())
	{
		std::cout << "Attemped to find scene that was not loaded" << std::endl;
		exit(1);
	}

	_current_scene = _scenes.find(id)->second;
}


void scene_manager::add_scene(scene* scene)
{
	if (_scenes.find(scene->id()) != _scenes.end())
	{
		std::cout << "Attemped to add a scene that conflicts with another scene." << scene->id()<<std::endl;
		exit(1);
	}
	_scenes[scene->id()] = scene;
}
