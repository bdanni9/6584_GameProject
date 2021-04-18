#pragma once

#include "game_object.h"

class mario : public game_object
{
public:

	//Constructor and Destructor
	mario(std::string id);
	~mario();

	//virtual void function for AI
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets,input* _input)override;
};

