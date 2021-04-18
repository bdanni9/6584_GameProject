#pragma once

#include "game_object.h"
#include "assets.h"

#include <stack>

class player : public game_object
{
public:
	//Constructors and Destructor
	player(std::string id);
	~player();

	//Adding states to the player
	enum class State
	{
		Idle,
		Walking,
		Running
	};
	void push_state(State state, assets* _assets);
	void pop_state(assets* _assets);

	//virtual void functions
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input)override;
	virtual void render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer,configuration* config,scene*_scene)override;

	//Setting the Speed function that can be used inside the game
	void set_speed(float speed);
	float speed();

private:

	void handle_enter_state(State state, assets* _assets);
	void handle_exit_state(State state, assets* _assets);
	
	float _speed;
	std::stack<State> _state;
};

