#pragma once

#include "scene.h"

class game_scene : public scene
{
public:
	game_scene();
	~game_scene();

	virtual void update(SDL_Window* window) override;


};