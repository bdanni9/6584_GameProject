#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "texture.h"
#include "asset.h"
#include "Vector_2D.h"


class text : public asset
{
public :
	text(SDL_Renderer* _renderer, const char* text, SDL_Color _color, std::string _id);
	~text();

	void render(SDL_Renderer* _renderer, Vector_2D tranlsation);

private:
	SDL_Texture* _data;
};

