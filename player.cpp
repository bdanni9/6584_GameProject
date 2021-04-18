#include "player.h"
#include "sound.h"


#include <iostream>
#include <SDL_mixer.h>


player::player(std::string id) :game_object(id, "Texture.Player.Walking")
{
	_translation = Vector_2D(0, 0);
	_velocity = Vector_2D(0.02f, 0);
	_speed = 0.1f;

	_mass = 1.0f;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

	_state.push(State::Idle);

}

player::~player()
{
}

void player::push_state(State state, assets* _assets)
{
	handle_exit_state(_state.top(), _assets);
	_state.push(state);
	handle_enter_state(_state.top(), _assets);
}

void player::pop_state(assets* _assets)
{
	handle_exit_state(_state.top(), _assets);

	_state.pop();
	handle_enter_state(_state.top(), _assets);
}

void player::simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input)
{

	switch (_state.top())
	{
	case State::Idle:
		if (_input->is_button_state(input::Button::RUNNING, input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::Running, _assets);
		}
		else if (_velocity.magnitude() > 0.0f)
		{
			push_state(State::Walking, _assets);
		}
		break;
	case State::Walking:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(_assets);
		}
		else if (_input->is_button_state(input::Button::RUNNING, input::Button_State::PRESSED))
		{
			push_state(State::Running, _assets);
		}
		break;
	case State::Running:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(_assets);
		}
		else if (_input->is_button_state(input::Button::RUNNING, input::Button_State::RELEASED))
		{
			pop_state(_assets);
		}
		break;
	}

	//Move Right and apply Velocity
	_velocity= Vector_2D(0, 0);
	if (_input->is_button_state(input::Button::RIGHT, input::Button_State::DOWN))
	{
		_velocity += Vector_2D(1.0f,0);
	}

	//Move Left and apply velocity
	if (_input->is_button_state(input::Button::LEFT, input::Button_State::DOWN))
	{
		_velocity += Vector_2D(-1.0f, 0);
	}

	//Move Up and apply velocity
	if (_input->is_button_state(input::Button::UP, input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, -1.0f);
	}

	//Move Down and apply velocity
	if (_input->is_button_state(input::Button::DOWN, input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 1.0f);
	}

	_velocity.normalize();
	_velocity.scale(_speed);

}



void player::render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer,configuration*config,scene*_scene)
{
	//Storing the animated texture inside the render function
	animated_texture* Texture = (animated_texture*)_assets->get_assets(_texture_id);
	Texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, _assets, renderer,config,_scene);
}

void player::set_speed(float speed)
{
	_speed = speed;
}

float player::speed()
{
	return _speed;
}

void player::handle_enter_state(State state, assets* _assets)
{
	switch (state)
	{
	case State::Idle:
		_texture_id = "Texture.Player.Idle";
		break;

	case State::Walking:
	{
		_texture_id = "Texture.Player.Walking";
		_speed = 0.05f;
		const int walking_channel = 1;
		sound* Sound = (sound*)_assets->get_assets("Sound.Walking");
		Mix_PlayChannel(walking_channel, Sound->data(), -1);
		break;
	}
		
	case State::Running:
	{
		_texture_id = "Texture.Player.Running";
		_speed = 0.1f;
		const int running_channel = 2;
		sound* Sound = (sound*)_assets->get_assets("Sound.Running");
		Mix_PlayChannel(running_channel, Sound->data(), -1);
		break;
	}
		
	}

}

void player::handle_exit_state(State state, assets* _assets)
{
	switch (state)
	{
	case player::State::Idle:
		break;
	case player::State::Walking:
	{
		const int walking_channel = 1;
		Mix_HaltChannel(walking_channel);
		break;
	}	
	case player::State::Running:
	{
		const int running_channel = 2;
		Mix_HaltChannel(running_channel); 
			break;
	}
	
	}
}

