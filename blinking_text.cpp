#include "blinking_text.h"
#include"text.h"

blinking_text::blinking_text(std::string text,Vector_2D translation) :game_object("Press F1 to Play", "Text.text")
{
	//Cache the position inside the blinking_texto constructor
	
	_translation = translation;
	_current_alpha = 255;

	_width = 200;
	_height = 200;

	_down = true;
}

blinking_text::~blinking_text()
{
}

void blinking_text::simulate_AI(Uint32 milliseconds_to_simulate, assets* _assets, input* _input,scene*_scene, game_manager* _game_manager)
{
}

void blinking_text::render(Uint32 milliseconds_to_simulate, assets* _assets, SDL_Renderer* renderer, configuration* config, scene* _scene)
{
	if (_down)
	{
		_current_alpha-=10;
		if (_current_alpha<=0)
		{
			_down = true;
		}
	}
	else
	{
		_current_alpha+=10;
		if (_current_alpha >= 255)
		{
			_down = false;
		}
	}


	SDL_Color text_color;
	text_color.r = 255;
	text_color.g = 255;
	text_color.b = 255;
	text_color.a = _current_alpha;
	_width = 200;
	_height = 200;
	text _id(renderer, _id.c_str(), text_color, "ID.Text");

	_id.render(renderer, _translation + Vector_2D((float)_width, (float)_height));
}
