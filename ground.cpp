#include "ground.h"

ground::ground(std::string id) :game_object(id, "Texture.Ground")
{
	//Cache the ground position inside the constructor

	_translation = Vector_2D(0, 600);
	_width = 800;
	_height = 200;

	//_mass = 1.0f;

	//_collider.set_radius(_width / 2.0f);
	//_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

ground::~ground()
{

}
 
void ground::simulate_AI(Uint32, assets*, input*)
{

}
