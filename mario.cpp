#include "mario.h"

mario::mario(std::string id):game_object(id,"Texture.Mario")
{
	//Cache the mario position inside the constructor

	_translation = Vector_2D(150, 100);


	_mass = 1.0f;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

mario::~mario()
{

}

void mario::simulate_AI(Uint32, assets*,input*)
{

}
