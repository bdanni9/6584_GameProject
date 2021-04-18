#pragma once

#include <Windows.h>
#include<string>

#include "input.h"
#include "scene.h"
#include "mario.h"

class editor
{
public:
	editor(std::wstring window_name);
	~editor();

	void update(input* _input, scene* _scene,configuration* config);


private:
	HWND _window;
	HMENU _menu;
};

