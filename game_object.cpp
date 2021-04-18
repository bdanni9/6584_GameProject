#pragma once

#include "game_object.h"
#include "text.h"

game_object::game_object(std::string id, std::string texture_id): _translation(0,0),_velocity(0,0),_collider(0.0f,Vector_2D(0.0f,0.0f))
{
	//Setting the default values inside the Constructor
	_id = id;
	_texture_id = texture_id;

	_width = 100;
	_height = 100;

	_flip = SDL_FLIP_NONE;
}

game_object::~game_object()
{
}

int game_object::width()
{
	return _width;
}

int game_object::height()
{
	return _height;
}


std::string game_object::id()
{
	return _id;
}

Circle_2D game_object::collider()
{
	return _collider;
}

Vector_2D game_object::translation()
{
	return _translation;
}

void game_object::set_translation(Vector_2D translation)
{
	_translation = translation;
}

void game_object::simulate_physics(Uint32 milliseconds_to_simulate, assets*,scene*_scene)
{
	Vector_2D velocity = _velocity;
	velocity.scale((float)milliseconds_to_simulate);

	_translation += velocity;

	for (game_object* GameObject : _scene->get_game_objects())
	{
		
		if (GameObject->id() == _id)
		{
			continue;
		}
		Circle_2D collider_for_this = Circle_2D(_collider.radius(), _collider.translation() + _translation);
		Circle_2D collider_for_other = Circle_2D(GameObject->_collider.radius(), GameObject->_collider.translation()+GameObject->_translation);


		Vector_2D this_to_other = collider_for_other.translation() - collider_for_this.translation();
		float distance_between_colliders = this_to_other.magnitude();

		float radius_combined = collider_for_this.radius() + collider_for_other.radius();

		bool we_are_colliding_Yo = distance_between_colliders < radius_combined;
		bool we_are_touching_yo = distance_between_colliders = radius_combined;
		bool we_are_not_even_close = distance_between_colliders > radius_combined;

		if (we_are_colliding_Yo)
		{
			std::cout << "We are Colliding" << std::endl;

			float ratioOfMassToMine = GameObject->_mass / _mass;

			Vector_2D repulsion_for_other = this_to_other;
			repulsion_for_other.normalize();
			repulsion_for_other.scale(0.5f);
			repulsion_for_other.scale(ratioOfMassToMine);
			GameObject->_translation += repulsion_for_other;

			float ratioOfMassToOther =  _mass / GameObject->_mass ;

			Vector_2D repulsion_for_this = collider_for_this.translation() - collider_for_other.translation();
			repulsion_for_this.normalize();
			repulsion_for_this.scale(0.5f);
			repulsion_for_other.scale(ratioOfMassToOther);
			_translation += repulsion_for_this;


		}

		//float how_far_do_these_intersect =  

	}
}

void game_object::render(Uint32, assets* assets, SDL_Renderer* renderer,configuration* config,scene* _scene)
{

	SDL_Rect destination;
	destination.x = (int)(_translation.x() - _scene->camera_translation().x());
	destination.y = (int)(_translation.y() - _scene->camera_translation().y());
	destination.w = _width;
	destination.h = _height;

	const float PI = 3.14159265f;
	if (_velocity.magnitude() > 0)
	{
		if (abs(_velocity.angle()) <= (PI / 2.f))
		{
			_flip = SDL_FLIP_NONE;
		}
		else
		{
			_flip = SDL_FLIP_HORIZONTAL;
		}
	}

	texture* Texture = (texture*)assets->get_assets(_texture_id);
	Texture->render(renderer, nullptr, &destination, _flip);


	if (config->should_display_ids)
	{
		SDL_Color text_color;
		text_color.r = 255;
		text_color.g = 255;
		text_color.b = 0;
		text_color.a = 255;

		text _id(renderer, _id.c_str(), text_color, "ID.Text");

		_id.render(renderer, _translation + Vector_2D((float)_width / 2, (float)_height));
	}

	if (config->should_display_colliders && _collider.radius() > 0.f)
	{
		texture* collider_texture = (texture*)assets->get_assets("Texture.Collider");

		SDL_Rect collider_destination;
		collider_destination.x = (int)(_translation.x() + _collider.translation().x() - _collider.radius());
		collider_destination.y = (int)(_translation.y() + _collider.translation().y() - _collider.radius());
		collider_destination.w = (int)(_collider.radius() * 2.0f);
		collider_destination.h = (int)(_collider.radius() * 2.0f);

		collider_texture->render(renderer, nullptr, &collider_destination, SDL_FLIP_NONE);
	}

}

