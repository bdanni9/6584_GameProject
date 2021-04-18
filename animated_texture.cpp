#include "animated_texture.h"
#include "texture.h"

//This is the animated texture constructor which will use to default the variables used inside the class as private
animated_texture::animated_texture(std:: string id, std::string path, SDL_Renderer* renderer, int frame_count, Uint32 frame_duration_milliseconds):texture(id,path, renderer)
{
	_frame_count = frame_count;
	_current_frame = 0;
	_frame_duration_milliseconds = frame_duration_milliseconds;
	_total_time_milliseconds = frame_duration_milliseconds;
	_data = new texture(id , path, renderer);
}

//Destructor will delete the data after using it
animated_texture::~animated_texture()
{
	delete _data;
}

//This will define the function to update the frameRate 
void animated_texture::update_frame(Uint32 milliseconds_to_simulate)
{
	_total_time_milliseconds += milliseconds_to_simulate;
	_current_frame = (_total_time_milliseconds / _frame_duration_milliseconds) % _frame_count;
}

//This is used to define the function to render the animated texture
void animated_texture::render(SDL_Renderer* renderer, SDL_Rect*, SDL_Rect* destination, SDL_RendererFlip flip)
{
	int texture_w = 0;
	int texture_h = 0;
	const int query_texture_result = SDL_QueryTexture(data(), nullptr, nullptr, &texture_w, &texture_h);

	const int frame_w = texture_w / _frame_count;

	SDL_Rect frame_clip;
	frame_clip.x = _current_frame * frame_w;
	frame_clip.y = 0;
	frame_clip.w = frame_w;
	frame_clip.h = texture_h;

	texture::render(renderer, &frame_clip, destination, flip);
}