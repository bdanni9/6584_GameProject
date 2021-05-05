#pragma once

#include"scene_manager.h"

class game_manager
{
public:
	game_manager();

	void update(scene_manager* _scene_manager);

	void lose_life() {_lives--;}

private:
	void spawn_live(scene_manager* _scene_manager);
	void Despawn_live(scene_manager* _scene_manager);

	int _lives;
	int _preious_lives;
	bool _has_initialized_UI;
	std::string _initialized_on_scene;
};

