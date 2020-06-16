#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "SDL_mixer.h"

class AudioPlayer {
  public:
    AudioPlayer();
    ~AudioPlayer();
    
    void PlayEatFood();
    void PlayDeath();
  private:
    Mix_Chunk *gEatFood {nullptr};
    Mix_Chunk *gDeath {nullptr};
};

#endif