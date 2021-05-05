#include "flymonster.h"

flymonster::flymonster(std::string id) :game_object("Monster", "Texture.Flying.Monster")
{
	//Cache the position inside the flymonstero constructor
	
	_height = 100;
	_width = 100;
	_translation = Vector_2D(350, 500);
	_velocity = Vector_2D(15.0f, 0);

	_mass = 1.0f;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

flymonster::~flymonster()
{
}

void flymonster::simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input,scene*_scene,game_manager*_game_manager)
{
}

void flymonster::render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer, configuration* config, scene* _scene)
{
	//Storing the animated texture inside the render function
	animated_texture* Texture = (animated_texture*)_assets->get_assets(_texture_id);
	Texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, _assets, renderer, config, _scene);
}
