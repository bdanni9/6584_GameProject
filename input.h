#pragma once

#include <map>

class input
{
public: 
	input();
	~input();
	//Creating Buttons for the Input
	enum class Button
	{
		QUIT,

		UP,
		DOWN,
		LEFT,
		RIGHT,
		JUMP,
		RUNNING,
		STARTBUTTON,

		INCREASE_SPEED,
		DECREASE_SPEED,
		SHOW_CREDITS,
		DEBUG_SHOW_IDS
	};
	//Creating Button States for the Input Buttons
	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP,
	};

	void get_input();
	bool is_button_state(Button type, Button_State state);

private:
	std::map<Button, Button_State> _button_state;
};

