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

	Button() = default;

	virtual void clickEvent(GameData *gameData) = 0;

	virtual ~Button() = default;
};

struct PauseButton : Button
{
	explicit PauseButton(Window *window);

	void clickEvent(GameData *gameData) override;

	~PauseButton() override = default;
};


struct StartButton : Button
{
	explicit StartButton(Window *window);

	void clickEvent(GameData *gameData) override;

	~StartButton() override = default;
};

struct ExitButton : Button
{
	explicit ExitButton(Window *window);

	void clickEvent(GameData *gameData) override;

	~ExitButton() override = default;
};

struct ContinueButton : Button
{
	explicit ContinueButton(Window *window);

	void clickEvent(GameData *gameData) override;

	~ContinueButton() override = default;
};

struct UI
{
	std::vector<std::vector<Button *> *> buttons;
	std::vector<Button *> mainMenuButtons;
	std::vector<Button *> gamingButtons;
	std::vector<Button *> pauseButtons;

	explicit UI(Window *window);

	//判断按钮点击并触发相应功能
	//在GameEvent中调用
	void clickButton(int x, int y, GameData *gameData);

	void refreshUI(Window *window, GameData *gameData);
};


#endif //PLANE_BATTLE_UI_H
