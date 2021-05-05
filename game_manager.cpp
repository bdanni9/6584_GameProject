#include "game_manager.h"
#include"health.h"
#include<string>

game_manager::game_manager()
{
	_lives = 3;
	_preious_lives = 3;
	_initialized_on_scene = "";
}

void game_manager::update(scene_manager* _scene_manager)
{
	scene* current_scene = _scene_manager->current_scene();
	bool has_not_initialized_UI = _initialized_on_scene.length() == 0
		||_initialized_on_scene!=_scene_manager->current_scene()->id();
	if (has_not_initialized_UI)
	{
		for (int health_index = 0; health_index < _lives; ++health_index)
		{
			spawn_live(_scene_manager);
		}
	}

	if (_preious_lives < _lives)
	{
		Despawn_live(_scene_manager);
	}
	if (_preious_lives > _lives)
	{
		spawn_live(_scene_manager);
	}

	if (_lives <= 0)
	{
		_scene_manager->set_current_scene("Game");
	}
}

void game_manager::spawn_live(scene_manager* _scene_manager)
{
	health* _health = new health(std::string("health") + std::to_string(_lives), Vector_2D(100 * _lives , 100));
	_scene_manager->current_scene()->add_game_object(_health);
}

void game_manager::Despawn_live(scene_manager* _scene_manager)
{
	//Health 1
	//Health 2 
	//Health 3

	// previous is one less then _lives

	std::string health_id = std::string("Health") + std::to_string(_preious_lives);
	_scene_manager->current_scene()->remove_game_object(health_id);

	_preious_lives = _lives;
}
