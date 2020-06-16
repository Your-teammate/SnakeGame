#include "audio_player.h"
#include <string>
#include <iostream>
#include "SDL.h"

AudioPlayer::AudioPlayer() {
  // Initializing SDL audio
  if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
    std::cerr << "SDL audio could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  
  // Initializing SDL_mixer
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048) < 0) {
    std::cerr << "SDL_mixer could not initialize.\n";
    std::cerr << "Mix_Error: " << Mix_GetError() << "\n";
  }
  
  // Loading sound effects
  gEatFood = Mix_LoadWAV("../sounds/eat_food.wav");
  if (gEatFood == nullptr) {
    std::cerr << "Failed to load \"eat_food.wav\".\n";
    std::cerr << "Mix_Error: " << Mix_GetError() << "\n";
  }
  gDeath = Mix_LoadWAV("../sounds/death.wav");
  if (gDeath == nullptr) {
    std::cerr << "Failed to load \"death.wav\".\n";
    std::cerr << "Mix_Error: " << Mix_GetError() << "\n";
  }
}

AudioPlayer::~AudioPlayer() {
  Mix_FreeChunk(gEatFood);
  gEatFood = nullptr;
  Mix_FreeChunk(gDeath);
  gDeath = nullptr;
  Mix_Quit();
}

void AudioPlayer::PlayEatFood() { Mix_PlayChannel(-1, gEatFood, 0); }

void AudioPlayer::PlayDeath() { Mix_PlayChannel(-1, gDeath, 0); }