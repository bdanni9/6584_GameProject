#include "health.h"

health::health(std::string id, Vector_2D translation) :game_object("health", "Texture.health")
{
	_translation = translation;

	_height = 100;
	_width = 100;
}

health::~health()
{

}

void health::simulate_AI(Uint32, assets*, input*, scene*, game_manager*)
{

}
