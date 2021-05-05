#include "assets.h"

#include <iostream>

#include "sound.h"

assets::assets(SDL_Renderer* renderer)
{
	#pragma region Cache the Texture and Animated Texture

#pragma region Logo
	{
		//Cache Mario Texture
		texture* LogoTexture = new texture("Texture.Logo", "Asserts/Logo.png", renderer);
		_assets[LogoTexture->id()] = LogoTexture;
	}
#pragma endregion

#pragma region Ground
{
		//Cache Ground Texture
		texture* groundTexture = new texture("Texture.Ground", "Asserts/Ground.png", renderer);
		_assets[groundTexture->id()] = groundTexture;
}
#pragma endregion

#pragma region Mario
	{
		//Cache Mario Texture
		texture* marioTexture = new texture("Texture.Mario", "Asserts/Mario.png", renderer);
		_assets[marioTexture->id()] = marioTexture;
	}
#pragma endregion

#pragma region Mario
	{
		//Cache Mario Texture
		texture* healthTexture = new texture("Texture.health", "Asserts/Heart.png", renderer);
		_assets[healthTexture->id()] = healthTexture;
	}
#pragma endregion

#pragma region Dino
	{
		//Cache Dino Walking Texture
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		animated_texture* texture = new animated_texture(
			"Texture.Dino.Walking",
			"Asserts/dino.walking.png",
			renderer,
			frame_count,
			frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}

#pragma endregion

#pragma region FlyingMonster
	{
		//Cache Dino Flying Monster Texture
		const int frame_count = 4;
		const Uint32 frame_duration_milliseconds = 100;
		animated_texture* texture = new animated_texture(
			"Texture.Flying.Monster",
			"Asserts/flying.monster.png",
			renderer,
			frame_count,
			frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}
#pragma endregion
#pragma region Player
	//Moving the Knight Player
		// Create player walking texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		asset* player_animated_texture = new animated_texture("Texture.Player.Walking", "Asserts/player.walking.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player running texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;	asset* player_animated_texture = new animated_texture("Texture.Player.Running", "Asserts/player.running.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player idle texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		asset* player_animated_texture = new animated_texture("Texture.Player.Idle", "Asserts/player.idle.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	//Create player jump texture
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		asset* player_animated_texture = new animated_texture("Texture.Player.Jumping", "Asserts/player.jumping.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

#pragma endregion

#pragma region Collider
	// Create collider texture
	{
		texture* colliderTexture = new texture("Texture.Collider", "Asserts/collider.png", renderer);
		_assets[colliderTexture->id()] = colliderTexture;
	}
#pragma endregion
	
#pragma region BackgroundMusic
	// Create music sound
	{
		sound* BgSound = new sound("Sound.Music", "Asserts/GameMusic.wav");
		_assets[BgSound->id()] = BgSound;

		Mix_PlayChannel(0, BgSound->data(), -1);
	}
#pragma endregion


#pragma region SFX Game
	{
		// Create walking sound
		{
			sound* SfxWalking = new sound("Sound.Walking", "Asserts/walking.wav");
			_assets[SfxWalking->id()] = SfxWalking;
		}

		// Create running sound
		{
			sound* SfxRunning = new sound("Sound.Running", "Asserts/running.wav");
			_assets[SfxRunning->id()] = SfxRunning;
		}
		// Create running sound
		{
			sound* SfxJumping = new sound("Sound.Jumping", "Asserts/jumping.wav");
			_assets[SfxJumping->id()] = SfxJumping;
		}


	}
#pragma endregion

#pragma endregion

	#pragma region Clean up For Assets
	////Setting a texture inside the assets class using texture as a reference
	//texture* mario_texture = new texture("Asserts/Mario.png", renderer);
	//_textures["Texture.Mario"] = mario_texture;

	//const int frame_count = 10;
	//const Uint32 frame_duration_milliseconds = 100;
	//animated_texture* walking_dino_texture = new animated_texture("Asserts/dino.walking.png", renderer, frame_count, frame_duration_milliseconds);
	//_animated_textures["Texture.Dino.Walking"] = walking_dino_texture;
#pragma endregion

}

assets::~assets()
{

}

#pragma region Unused Cleaned up functions when We Implemented Assets as ID
//texture* assets::get_texture(std::string id)
	#pragma region Clean up Texture
	//if (_textures.find(id) == _textures.end())
	//{
	//	std::cout << "Attempted to find a texture that was not loaded. ID: " << id << std::endl;
	//	exit(1);
	//}

	////This will store the memory location of the texture stored
//	return _textures[id];
//#pragma endregion	
//}
//
//animated_texture* assets::get_animated_texture(std::string id)
	#pragma region Clean up Animated Texture
	///*if (_animated_textures.find(id) == _animated_textures.end())
	//{
	//	std::cout << "Attempted to find an animated texture that was not loaded. ID: " << id << std::endl;
	//	exit(1);
	//}*/

	//return _animated_textures[id];

#pragma endregion
#pragma endregion
#pragma endregion


asset* assets::get_assets(std::string id)
{
	if (_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID" << id << std::endl;
	}
	return _assets[id];
}
