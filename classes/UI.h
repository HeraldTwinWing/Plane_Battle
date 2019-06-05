//
// Created by Avala on 2019/5/29.
//

#ifndef PLANE_BATTLE_UI_H
#define PLANE_BATTLE_UI_H

#include <SDL2/SDL.h>
#include "GameData.h"
#include "Window.h"
#include <vector>


struct Button
{

	SDL_Texture *texture;
	SDL_Rect positionAndSize;

	bool effective;


	Button();

	virtual void clickEvent(GameData *gameData) = 0;

	virtual ~Button() = default;
};

struct PauseButton : Button
{
	PauseButton(Window *window);

	explicit PauseButton(SDL_Rect);

	void clickEvent(GameData *gameData) override;

	~PauseButton() override = default;
};


struct StartButton : Button
{
	StartButton(Window *window);

	explicit StartButton(SDL_Rect positionAndSize);

	void clickEvent(GameData *gameData) override;

	~StartButton() override = default;
};

struct ExitButton : Button
{
	ExitButton(int x, int y, int w, int h, Window *window);

	explicit ExitButton(SDL_Rect positionAndSize);

	void clickEvent(GameData *gameData) override;

	~ExitButton() override = default;
};

struct UI
{
	std::vector<Button *> buttons;

	explicit UI(Window *window);

	//�жϰ�ť�����������Ӧ����
	//��GameEvent�е���
	void clickButton(int x, int y, GameData *gameData);

	void showButton(Window *window);
};


#endif //PLANE_BATTLE_UI_H