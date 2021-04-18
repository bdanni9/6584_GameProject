#pragma once

//Including the SDL inside the main
#define SDL_MAIN_HANDLED
#include <SDL.h>

//Include the required classes
#include "texture.h"
#include"asset.h"

//Making the asset a public so the animated texture can inherit from asset
class animated_texture : public texture
{
public:
	//Constructor and Destructor
	animated_texture(std::string id, std::string path, SDL_Renderer* renderer, int frame_count, Uint32 frame_duration_milliseconds);
	~animated_texture();

	//This function will update the framerate
	void update_frame(Uint32 milliseconds_to_simulate);
	//This is used to specifiy the animated texture render
	void render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, SDL_RendererFlip flip)override;

private:
	//Private variables used for the Animated Texture
	int      _frame_count;
	Uint32   _frame_duration_milliseconds;
	Uint32   _total_time_milliseconds;
	int      _current_frame;
	texture* _data;
};
