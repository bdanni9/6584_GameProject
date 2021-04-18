#pragma  once

#include "editor.h"
#include "resource.h"
#include "player.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>


editor::editor(std::wstring window_name)
{
	//Here we are initializing the Window name
	_window = FindWindow(NULL, window_name.c_str());
	if (_window == NULL)
	{
		std::cout << "Failed to find the window. Window Name :" << window_name.c_str() << std::endl;
		exit(1);
	}
	//Here we are initializing the Menu name
	_menu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
	if (_menu == NULL)
	{
		std::cout << "Failed to Create Menu:"<< std::endl;
		exit(1);
	}

	//Here we are checking if we found the menu name and window 
	BOOL set_menu_result = SetMenu(_window, _menu);
	if (set_menu_result == NULL)
	{
		std::cout << "Failed to set menu" << std::endl;
		exit(1);
	}

	//Here we are enabling the window with the menu
	Uint8 event_state_result = SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
	Uint8 event_state_success = SDL_DISABLE;
	if (event_state_result != event_state_success)
	{
		std::cout << "Failed to enable the windows event state." << std::endl;
		exit(1);
	}

}

editor::~editor()
{

}
INT_PTR CALLBACK Dialog_Proc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
	switch (Message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
			EndDialog(hwnd, IDOK);
			break;
		}
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

void editor::update(input* _input, scene* _scene,configuration* config)
{
	//Updating the Speed using the menu editor
	
	if (_input->is_button_state(input::Button::INCREASE_SPEED, input::Button_State::PRESSED))
	{
		player* _player = (player*)_scene->get_game_object("Player.Walking");
		_player->set_speed(_player->speed() * 1.1f);
	}

	if (_input->is_button_state(input::Button::DECREASE_SPEED, input::Button_State::PRESSED))
	{
		player* _player = (player*)_scene->get_game_object("Player.Walking");
		_player->set_speed(_player->speed() * 0.8f);
	}
	if (_input->is_button_state(input::Button::SHOW_CREDITS, input::Button_State::PRESSED))
	{
		DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), _window, Dialog_Proc);
	}
	if (_input->is_button_state(input::Button::DEBUG_SHOW_IDS, input::Button_State::PRESSED))
	{
		config->should_display_ids = !config->should_display_ids;
	}

}


