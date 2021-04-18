#pragma once


//Including the SDL library inside the game_object Class
#define SDL_MAIN_HANDLED
#include<SDL.h>

//Including the Asserts class
#include"assets.h"
#include "input.h"
#include "Vector_2D.h"
#include "circle_2D.h"
#include"configuration.h"
#include "scene.h"

class game_object
{
public:
	//Constructors and Destructor
	game_object(std::string id , std::string texture_id);
	~game_object();

	std::string id();
	Circle_2D collider();

	//These are virtual functions 
	virtual void simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets,input* _input) = 0;
	virtual void simulate_physics(Uint32 milliseconds_to_simulate, assets* _assets,scene* _scene) ;
	virtual void render(Uint32 milliseconds_to_simulate, assets* assets,SDL_Renderer* renderer,configuration* config,scene* _scene) ;
	void set_translation(Vector_2D _translation);

	Vector_2D translation();

	//Variables
	int height();
	int width();
protected:

	//Cache the id and texture id
	std::string _id;
	std::string _texture_id;

	Circle_2D _collider;

	//Caching the values
	/*int _x;
	int _y;*/

	//Changing the _x and _y with velocities
	Vector_2D _translation;
	Vector_2D _velocity;

	int _width;
	int _height;

	float _mass;

	//Caching the flip
	SDL_RendererFlip _flip;


};

