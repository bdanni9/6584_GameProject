#include "text.h"

#include <SDL_ttf.h>
#include <iostream>

text::text(SDL_Renderer* _renderer, const char* text, SDL_Color _color, std::string _id):asset(_id)
{
	TTF_Font* font = TTF_OpenFont("Asserts/HARLOWSI.ttf", 15);
	if (font == nullptr)
	{
		std::cout << "Failed to load font." << std::endl;
		std::cout << "SDL Error" << std::endl;
		exit(1);
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, text, _color);
	if (surface == nullptr)
	{
		std::cout << "Failed to create surface from font." << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	_data = SDL_CreateTextureFromSurface(_renderer, surface);
	if (_data == nullptr)
	{
		std::cout << "Failed to create texture from surface." << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_FreeSurface(surface);
}

text::~text()
{
	SDL_DestroyTexture(_data);
}

void text::render(SDL_Renderer* _renderer, Vector_2D tranlsation)
{
	SDL_Rect destination = { (int)tranlsation.x(), (int)tranlsation.y(), 0, 0 };
	SDL_QueryTexture(_data, nullptr, nullptr, &destination.w, &destination.h);
	SDL_RenderCopy(_renderer, _data, NULL, &destination);
}
