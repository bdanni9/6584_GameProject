#include "walking_dino.h"

walking_dino::walking_dino(std::string id):game_object(id, "Texture.Dino.Walking")
{
	//Cache the position inside the walking_dinoo constructor
	_translation = Vector_2D(250, 150);
	_velocity = Vector_2D(0.02f, 0);

	_mass = 1.0f;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

walking_dino::~walking_dino()
{
}

void walking_dino::simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets,input*_input)
{
}

void walking_dino::render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer,configuration*config,scene*_scene)
{
	//Storing the animated texture inside the render function
	animated_texture* Texture = (animated_texture*)_assets->get_assets(_texture_id);
	Texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, _assets, renderer,config,_scene);
}
