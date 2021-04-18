#include<iostream>

//Include the SDL inside the Engine 
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "engine.h"
#include"texture.h"
#include "game_object.h"
#include "Vector_2D.h"
#include"scene.h"


//We do not need these anymore
//#include "mario.h"
//#include "walking_dino.h"

engine::engine(std::string window_name, configuration* config)
{
	//Initializing the Init Function from SDL inside the Engine Constructor
	const int init_result = SDL_Init(SDL_INIT_EVERYTHING);
	const int init_result_success = 0;

	if (init_result != init_result_success)
	{
		std::cout << "Failed to initialize SDL" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	// Creating a window using SDL_CreateWindow
	const char* game_title = window_name.c_str();
	const int x = 100;
	const int y = 100;
	const int w = 600;
	const int h = 600;
	_window = SDL_CreateWindow(game_title, x, y, config->window_with,config->window_height, SDL_WINDOW_RESIZABLE);
	if (_window == nullptr)
	{
		std::cout << "Failed to create SDL window" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	const int first_renderer = -1;

	_renderer = SDL_CreateRenderer(_window, first_renderer, 0);

	if (_renderer == nullptr)
	{
		std::cout << "Failed to create Renderer" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}
	
	const int mixer_init_result = Mix_Init(MIX_INIT_MOD);
	const int mixer_init_failure = 0;
	if (mixer_init_result == mixer_init_failure)
	{
		std::cout << "Failed to initialize SDL Mixer" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		std::cout << "Mixer Error: " << Mix_GetError() << std::endl;
		exit(1);
	}

	const int mixer_open_audio_result = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	const int mixer_open_audio_success = 0;
	if (mixer_open_audio_result != mixer_open_audio_success)
	{
		std::cout << "Failed to open audio" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	Mix_AllocateChannels(3);
}

engine::~engine()
{
	

}

void engine::simualte(Uint32 milliseconds_to_simulate,assets* _assets,scene* _scene,input* _input, configuration* config)
{
	//We will run the functions inside this simulate function constructor
	simulate_AI(milliseconds_to_simulate,_assets,_scene,_input);
	simulate_physics(milliseconds_to_simulate,_assets,_scene);
	render(milliseconds_to_simulate, _assets,_scene,_input, config);
}


void engine::simulate_AI(Uint32, assets*,scene*,input*)
{
}

void engine::simulate_physics(Uint32 milliseconds_to_simulate, assets*_assets ,scene*_scene)
{
	std::vector<game_object*> game_objects = _scene->get_game_objects();
	for (game_object* game_object : game_objects)
	{
		game_object->simulate_physics(milliseconds_to_simulate, _assets,_scene);
	}

}

void engine::render(Uint32  milliseconds_to_simulate, assets* _assets,scene* _scene,input* _input,configuration* config)
{
	// Creating and clearing the renderer using SDL_CreateWindow
	const int render_clear_success = 0;
	const int render_clear_result = SDL_RenderClear(_renderer);

	if (render_clear_result != render_clear_success)
	{
		std::cout << "Failed to clear renderer" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//Initializing Text into the Engine
	const int ttf_init_result = TTF_Init();
	const int ttf_init_success = 0;
	if (ttf_init_result != ttf_init_success)
	{
		std::cout << "Failed to initialize SDL TTF" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//Setting colors inside the window using the renderer 
	//We will set the color to blue using these constants
	const Uint8 red = _scene->_red;
	const Uint8 green = _scene->_green;
	const Uint8 blue = _scene->_blue;
	const Uint8 alpha = 255;
	const int render_color_success = 0;
	const int render_color_result = SDL_SetRenderDrawColor(_renderer, red, green, blue, alpha);

	//If the render fails to set render color
	if (render_color_result != render_color_success)
	{
		std::cout << "Failed to set render color" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	{	
		#pragma region Texture Class image Rendering
		//Here we will try to render the Image
		//This is method one of rendering the image from the Texture class
		/*texture dino = texture("Asserts/dino.bmp", _renderer);
		SDL_Rect destination;
		destination.x = 50;
		destination.y = 50;
		destination.w = 100;
		destination.h = 100;

		dino.render(_renderer, nullptr, &destination, SDL_FLIP_NONE);*/
	#pragma endregion
	}

	{
		#pragma region Mario Texture
		//Here we will try to render the Image using the assets class
		//texture* mario = (texture*)_assets->get_assets("Texture.Mario");
		//SDL_Rect destination;
		//destination.x = 50;
		//destination.y = 50;
		//destination.w = 100;
		//destination.h = 100;
		//mario->render(_renderer, nullptr, &destination, SDL_FLIP_NONE);
	#pragma endregion
	}
	
	{
		#pragma region Walking Dino
		//Here we will try to render the Animated texture 
		/*animated_texture* walking_dino_texture =(animated_texture*) _assets->get_assets("Texture.Dino.Walking")*/;

		// This will update the frame to the given frame rate inside the assets
		
		/*walking_dino_texture->update_frame(milliseconds_to_simulate);

		SDL_Rect destination;
		destination.x = 150;
		destination.y = 50;
		destination.w = 100;
		destination.h = 100;
		walking_dino_texture->render(_renderer, nullptr, &destination, SDL_FLIP_NONE);*/
	#pragma endregion
	}

	{
		#pragma region Using GameObject to Render Texture
	/*	mario* man = new mario("Mario");
		man->render(milliseconds_to_simulate, _assets, _renderer);*/
#pragma endregion
	}

	{
		#pragma region Using GameObject to Render Animated Texture
				// Here is the code to render the animated texture
		//walking_dino* Rex = new walking_dino("Texture.Dino.Walking");
		//Rex->render(milliseconds_to_simulate, _assets, _renderer);

		#pragma endregion
	}

	std::vector<game_object*> game_objects = _scene->get_game_objects();
	for (game_object* game_object : game_objects)
	{
		game_object->render(milliseconds_to_simulate, _assets, _renderer,config,_scene);
		game_object->simulate_AI(milliseconds_to_simulate, _assets, _input);
		game_object->simulate_physics(milliseconds_to_simulate, _assets,_scene);
	}


	//This will Present the Render with the color which is set above 
	SDL_RenderPresent(_renderer);
}

SDL_Renderer* engine::renderer()
{

	return _renderer;
}

SDL_Window* engine::window()
{
	return _window;
}

