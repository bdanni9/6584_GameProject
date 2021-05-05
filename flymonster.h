#pragma once

#include "game_object.h"

class flymonster : public game_object
{
public:
	//Constructors and Destructors
	flymonster(std::string id);
	~flymonster();

	//virtual void functions
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input,scene*_scene,game_manager*_game_manger)override;
	virtual void render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer, configuration* config, scene* _scene)override;

};

