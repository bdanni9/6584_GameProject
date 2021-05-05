#pragma once

#include "scene.h"

class gameover_scene : public scene
{

public:
	gameover_scene();
	~gameover_scene();

	virtual void update(SDL_Window* window) override;
};