#include "logo.h"

logo::logo(std::string id) :game_object(id, "Texture.Logo")
{
	//Cache the logo position inside the constructor

	_translation = Vector_2D(300, 0);
	_width = 300;
	_height = 300;

	_mass = 1.0f;

	_collider.set_radius(_width / 2.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

logo::~logo()
{

}

void logo::simulate_AI(Uint32, assets*, input*,scene*,game_manager*)
{

}
