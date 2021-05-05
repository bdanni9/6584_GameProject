#pragma once
#include"scene.h"
#include<string>
#include<map>

class scene_manager
{
public:
	scene_manager();

	scene* current_scene();

	void set_current_scene(std::string id);
	void add_scene(scene* scene);
private:
	std::map < std::string, scene*> _scenes;
	scene* _current_scene;
};

