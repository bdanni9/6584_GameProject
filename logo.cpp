#include "logo.h"

logo::logo(std::string id) :game_object(id, "Texture.Logo")
{
	//Cache the logo position inside the constructor

	_translation = Vector_2D(200, 50);
	_width = 500;
	_height = 500;

	_mass = 1.0f;

	_collider.set_radius(_width / 2.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

logo::~logo()
{

}

void logo::simulate_AI(Uint32, assets*, input*)
{

}
