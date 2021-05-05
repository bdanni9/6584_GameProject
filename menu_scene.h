#pragma once

#include "scene.h"

class menu_scene : public scene
{
public:
	menu_scene();
	~menu_scene();

	void Reset() override;

	virtual void update(SDL_Window* window) override;
};