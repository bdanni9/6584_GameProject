#include "player.h"
#include "sound.h"


#include <iostream>
#include <SDL_mixer.h>


player::player(std::string id) :game_object(id, "Texture.Player.Walking"), _jumpvelocity(0.f, 0.f)
{
	_translation = Vector_2D(0, 400);
	_velocity = Vector_2D(0, 0);
	_speed = 0.1f;

	_mass = 10.0f;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

	_initialized = false;
	isEffectedByGravity = true;

}

player::~player()
{
}

void player::push_state(State state, assets* _assets)
{
	bool am_currently_in_a_state = _state.size() > 0;
	if(am_currently_in_a_state) handle_exit_state(_state.top(), _assets);
	_state.push(state);
	handle_enter_state(_state.top(), _assets);
}

void player::pop_state(assets* _assets)
{
	handle_exit_state(_state.top(), _assets);

	_state.pop();
	handle_enter_state(_state.top(), _assets);
}

void player::simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input,scene*_scene,game_manager*_game_manager)
{
	if(!_initialized)
	{
		push_state(State::Idle, _assets);
		_initialized = true;
	}

	switch (_state.top())
	{
	case State::Idle:
	{
		bool am_walking = _velocity.x() != 0.0f;
		if (am_walking)
		{
			push_state(State::Walking, _assets);
		}
		break;
	}
	case State::Walking:
		if (_velocity.x() == 0.0f)
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
	case State::Jumping:
		bool we_are_grounded = _velocity.y() == 0.f;
		if(we_are_grounded)
		{
			pop_state(_assets);
		}

		break;
		
	}
	//Jump up and apply velocity
	if (_input->is_button_state(input::Button::JUMPING, input::Button_State::PRESSED))
	{
		_velocity.set_y(-160.f);

		push_state(State::Jumping, _assets);

		//_jumpvelocity += Vector_2D(0.0f, -0.1f);
	}

	//Move Right and apply Velocity
	
	_velocity.set_x(0.0f);
	if (_input->is_button_state(input::Button::RIGHT, input::Button_State::DOWN))
	{
		_velocity.set_x(76.0f);
	}

	//Move Left and apply velocity
	if (_input->is_button_state(input::Button::LEFT, input::Button_State::DOWN))
	{
		_velocity.set_x(-76.0f);
	}
	//We commented this because we dont want to move up and down based on the key movment
	////Move Up and apply velocity
	//if (_input->is_button_state(input::Button::UP, input::Button_State::DOWN))
	//{
	//	_velocity += Vector_2D(0, -1.0f);
	//}

	////Move Down and apply velocity
	//if (_input->is_button_state(input::Button::DOWN, input::Button_State::DOWN))
	//{
	//	_velocity += Vector_2D(0, 1.0f);
	//}

	//If Mario is the Killer
	/*game_object* player = _scene->get_game_object("Mario");

	Vector_2D mario_center = _translation + Vector_2D((float)_width / 2, (float)_height / 2);
	Vector_2D marios_center = player->translation() + Vector_2D((float)player->width() / 2, (float)player->height() / 2);

	float distance_to_mario = (mario_center - marios_center).magnitude();
	if (distance_to_mario < 50.0f)
	{
		_game_manager->lose_life();
		_scene->Reset();
	}*/

	//If Monster is the killer
	game_object* player = _scene->get_game_object("Monster");

	Vector_2D Monster_center = _translation + Vector_2D((float)_width / 2, (float)_height / 2);
	Vector_2D Monsters_center = player->translation() + Vector_2D((float)player->width() / 2, (float)player->height() / 2);

	float distance_to_Monster = (Monster_center - Monsters_center).magnitude();
	if (distance_to_Monster < 50.0f)
	{
		_game_manager->lose_life();
		_scene->Reset();
	}
}



void player::render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer,configuration*config,scene*_scene)
{
	//Storing the animated texture inside the render function
	animated_texture* Texture = (animated_texture*)_assets->get_assets(_texture_id);
	Texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, _assets, renderer,config,_scene);
}

void player::simulate_physics(Uint32 milliseconds_to_simulate, assets* _assets, scene* _scene)
{
	//_velocity = _jumpvelocity;


	game_object::simulate_physics(milliseconds_to_simulate, _assets, _scene);

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
		_speed = 0.15f;
		const int running_channel = 2;
		sound* Sound = (sound*)_assets->get_assets("Sound.Running");
		Mix_PlayChannel(running_channel, Sound->data(), -1);
		break;
	}
	case State::Jumping:
	{
		_texture_id = "Texture.Player.Jumping";
		const int jumping_channel = 3;
		sound* Sound = (sound*)_assets->get_assets("Sound.Jumping");
		Mix_PlayChannel(jumping_channel, Sound->data(), 0);
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
	case player::State::Jumping:
	{
		const int jumping_channel = 3;
		Mix_HaltChannel(jumping_channel);
		break;
	}
	
	}
}

