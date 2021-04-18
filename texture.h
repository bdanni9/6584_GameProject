#pragma once

#include<iostream>

//Including the SDL inside the class
#define SDL_MAIN_HANDLED
#include <SDL.h>

//Including the asset class 
#include"asset.h"

//Making the asset a public so the texture can inherit from asset
class texture : public asset
{
public:
	//Creating the Constructor and Destructor
	texture(std::string id,std::string path, SDL_Renderer* renderer);
	~texture();

	//Creating a SDL_Texture Function
	SDL_Texture* data();

	//Creating a Render Function
	virtual void render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, SDL_RendererFlip flip);

private:
	//Creating private SDL_Texture pointer
	SDL_Texture* _data;
};

