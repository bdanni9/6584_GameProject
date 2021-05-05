#pragma once

#include "game_object.h"

class blinking_text : public game_object
{
public:
	//Constructors and Destructors
	blinking_text(std::string text,Vector_2D translation);
	~blinking_text();

	//virtual void functions
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input,scene*_scene,game_manager*_game_manager)override;
	virtual void render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer, configuration* config, scene* _scene)override;

	std::string _text;
	Uint8 _current_alpha;
	int w=200;
	int h=200;
	bool _down;
};