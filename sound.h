#pragma once

#include"asset.h"

#include<SDL_mixer.h>

class sound: public asset
{
public :
	sound(std::string id, std::string path);
	Mix_Chunk* data();

private:
	Mix_Chunk* _data;
};

