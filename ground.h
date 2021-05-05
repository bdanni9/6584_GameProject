#pragma once

#include "game_object.h"

class ground : public game_object
{
public:

	//Constructor and Destructor
	ground(std::string id);
	~ground();

	//virtual void function for AI
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input,scene*_scene,game_manager*_game_manager)override;
};