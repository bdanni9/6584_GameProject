#include <iostream>

#include "texture.h"

//Including the SDL Image library to use images inside the class
#include <SDL_image.h>

//Initilizing the Constructor 
//Texture will inherit the asset id by the below step
texture::texture(std::string id,std::string path, SDL_Renderer* renderer): asset(id)
{
	//Uploading the Bmp and Png Images into the Texture class
	SDL_Surface* surface = nullptr;
	if (path.find("bmp") != std::string::npos)
	{
		surface = SDL_LoadBMP(path.c_str());
	}
	else if (path.find("png") != std::string::npos)
	{
		surface = IMG_Load(path.c_str());
	}
	else
	{
		std::cout << "Unknown image file extension. Path: " << path << std::endl;
		exit(1);
	}

	//If it fails to load the files
	if (surface == nullptr)
	{
		std::cout << "Failed to load image. Path: " << path << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//This will create a surface for the image file
	_data = SDL_CreateTextureFromSurface(renderer, surface);

	//if it fails to load the file
	if (_data == nullptr)
	{
		std::cout << "Failed to create texture. Path: " << path << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//This will represent the surface
	SDL_FreeSurface(surface);
}

texture::~texture()
{
	//Destroy the Texture
	SDL_DestroyTexture(_data);
}
SDL_Texture* texture::data()
{
	return _data;
}

void texture::render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, SDL_RendererFlip flip)
{
	//This will render the clip onto the renderer
	const int render_result = SDL_RenderCopyEx(renderer, _data, clip, destination, 0, nullptr, flip);
	const int render_success = 0;
	if (render_result != render_success)
	{
		std::cout << "Failed to render texture" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		exit(1);
	}
}
