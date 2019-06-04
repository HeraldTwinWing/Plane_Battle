//
// Created by Avala on 2019/4/9.
//

#pragma once

#include <SDL2/SDL.h>
#include "GameData.h"


class GameEvent
{
public:
    GameData *gameData = nullptr;

    GameEvent()= default;

    explicit GameEvent(GameData* game_data);

	virtual ~GameEvent();

	virtual void OnEvent(SDL_Event &Event);

	virtual void OnInputFocus();

	virtual void OnInputBlur();

	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);

	virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod);

	virtual void OnMouseFocus();

	virtual void OnMouseBlur();

	virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);

	virtual void OnMouseWheel(bool Up, bool Down);

	virtual void OnLButtonDown(int mX, int mY);

	virtual void OnLButtonUp(int mX, int mY);

	virtual void OnRButtonDown(int mX, int mY);

	virtual void OnRButtonUp(int mX, int mY);

	virtual void OnMButtonDown(int mX, int mY);

	virtual void OnMButtonUp(int mX, int mY);

	virtual void OnJoyAxis(SDL_JoystickID which, Uint8 axis, Sint16 value);

	virtual void OnJoyButtonDown(SDL_JoystickID which, Uint8 button);

	virtual void OnJoyButtonUp(SDL_JoystickID which, Uint8 button);

	virtual void OnJoyHat(SDL_JoystickID which, Uint8 hat, Uint8 value);

	virtual void OnJoyBall(SDL_JoystickID which, Uint8 ball, Sint16 xrel, Sint16 yrel);

	virtual void OnExpose();

	virtual void OnExit();

    virtual void OnUser(Uint32 type, int code, void *data1, void *data2);
};


