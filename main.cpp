#include<iostream>
#include <chrono>
#include <thread>
#include<stack>

//Including the SDL inside the main
#define SDL_MAIN_HANDLED
#include<SDL.h>

//Including Classes inside the main
#include"engine.h"
#include "input.h"
#include"editor.h"
#include "configuration.h"
#include "menu_scene.h"
#include"scene_manager.h"
#include"gameover_scene.h"
#include "game_manager.h"

int main(void)
{
	//Creating Configuration reference
	configuration* config = new configuration();

	// Creating a new Engine reference
	engine* Engine = new engine("Game",config);
	// Creating a new Asset reference
	assets* _assets = new assets(Engine->renderer());

	////Creating a new Scene reference
	//scene* gameScene = new game_scene();

	////Creating a new Menu Scene reference
	//scene* menuScene = new menu_scene();

	//Creating a Input reference
	input* _input = new input();

	//Creating a Editor reference
	editor* _editor = new editor(L"Game");

	//Creatring a Scene manager reference
	scene_manager* _scene_manager = new scene_manager();

	//Creating a game manager reference
	game_manager* _game_manager = new game_manager();
	
	
	_scene_manager->add_scene(new menu_scene());
	_scene_manager->add_scene(new game_scene());
	//_scene_manager->add_scene(new gameover_scene());
	_scene_manager->set_current_scene("Game");

	//
	
	//if (_scene_manager->set_current_scene("Menu") && _input->is_button_state(input::Button::STARTBUTTON, input::Button_State::PRESSED))
	//{
	//	_scene_manager->set_current_scene("Game");
	//	std::cout << "StartGame" << std::endl;
	//}

	//Using stack for the game scenes
	std::stack<scene*> scenes;
	scenes.push(new menu_scene());

	const Uint32 milliseconds_per_seconds = 1000;
	const Uint32 frames_per_second = 60;
	const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

	Uint32 frame_start_time_ms = 0;
	Uint32 frame_end_time_ms = frame_time_ms;

	//Running a while loop inside the main
	while (!_input->is_button_state(input::Button::QUIT, input::Button_State::PRESSED))
	{
		Uint32 previous_frame_duration = frame_end_time_ms - frame_start_time_ms;
		frame_start_time_ms = SDL_GetTicks();

		scene* top_scene = scenes.top();

		scenes.top()->update(Engine->window());
		_input->get_input();
		Engine->simualte(previous_frame_duration, _assets, top_scene,_input,config,_game_manager);
		_editor->update(_input, _scene_manager->current_scene(),config);

		/*if (top_scene->id()=="Menu" &&_input->is_button_state(input::Button::STARTBUTTON, input::Button_State::PRESSED))
		{
			scenes.push(new game_scene());
			std::cout << "StartGame" << std::endl;
		}*/

// Debuggeroni
	/*	if (_input->is_button_state(input::Button::UP, input::Button_State::PRESSED))
		{
			std::cout << "UP PRESSED!!!!" << std::endl;
		}

		if (_input->is_button_state(input::Button::DOWN, input::Button_State::PRESSED))
		{
			std::cout << "Here is Down" << std::endl;
		}
		if (_input->is_button_state(input::Button::RIGHT, input::Button_State::PRESSED))
		{
			std::cout << "Here is right" << std::endl;
		}
		if (_input->is_button_state(input::Button::LEFT, input::Button_State::PRESSED))
		{
			std::cout << "Here is Left" << std::endl;
		}*/

		const Uint32 current_time_ms = SDL_GetTicks();
		const Uint32 frame_duration_ms = current_time_ms - frame_start_time_ms;
		if (frame_duration_ms < frame_time_ms)
		{
			const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
			std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
		}

		frame_end_time_ms = SDL_GetTicks();
	}
	
	return 0;
}