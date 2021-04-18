#pragma once

//Including the map 
#include <map>

//Including the Texture class and animated texture class
#include "texture.h"
#include"animated_texture.h"
#include"asset.h"

class assets
{
public:

	//Constructor and Destructor
	assets(SDL_Renderer* renderer);
	~assets();

	#pragma region Unused functions after using Assets as the ID

	//Functions which will be used to retrieve the textures and animated textures
	/*texture* get_texture(std::string id);
	animated_texture* get_animated_texture(std::string id);*/
#pragma endregion

	//This function will provides assets from the map
	asset* get_assets(std::string id);

private:
	// We will make an asset map instead of the texture and animated texture to clean up the assets class
	std::map<std::string, asset*> _assets;

	#pragma region Clean up 
	//They will store the map location of the textures and animated textures
	/*std::map<std::string, texture*> _textures;
	std::map<std::string, animated_texture*> _animated_textures;*/
#pragma endregion

	

};

