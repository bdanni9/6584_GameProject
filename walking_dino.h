#pragma once

#include "game_object.h"

class walking_dino: public game_object
{
public:
	//Constructors and Destructors
	walking_dino(std::string id);
	~walking_dino();

	//virtual void functions
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets,input* _input)override;
	virtual void render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer,configuration* config,scene*_scene)override;

};

