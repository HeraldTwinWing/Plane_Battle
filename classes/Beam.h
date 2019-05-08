//
// Created by Avala on 2019/5/7.
//

#ifndef PLANE_BATTLE_BEAM_H
#define PLANE_BATTLE_BEAM_H

#include <SDL2/SDL.h>

class Beam
{
public:
    SDL_Texture* texture;
    SDL_Rect position;
    int atk;
    int width;

    int getAtk()
    {
        return atk;
    }

    ~Beam()  = default;
};


#endif //PLANE_BATTLE_BEAM_H
