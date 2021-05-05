#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>


#include "assets.h"
#include "scene.h"
#include "game_scene.h"
#include "input.h"
#include "configuration.h"
#include"scene.h"
#include"game_manager.h"

class engine
{
public:
	//Constructors and Destructor
	engine(std::string window_name,configuration* config);
	~engine();

	//Functions used inside the public engine class
	void simualte(Uint32 milliseconds_to_simulate,assets* _assets,scene* _scene,input* _input, configuration* config,game_manager* _game_manager);

	//Functions used to create the render and window
	SDL_Renderer* renderer();
	SDL_Window* window();

	static engine* instance;
	
private:
	//Functions used inside the engine class
	void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets,scene* _scene,input*_input,game_manager*_game_manager);
	void simulate_physics(Uint32 milliseconds_to_simulate,assets* _assets,scene* _scene);
	void render(Uint32 milliseconds_to_simulate,assets* _assets,scene* _scene,input* _input, configuration* config);

	//Creating private properties of Engine
	SDL_Window* _window;
	SDL_Renderer* _renderer;

};

