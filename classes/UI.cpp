//
// Created by Avala on 2019/5/29.
//

#include "UI.h"

Button::Button() = default;

PauseButton::PauseButton(Window *window)
{
	effective = false;
	/*
	positionAndSize.x = ;
	positionAndSize.y = y;
	positionAndSize.h = h;
	positionAndSize.w = w;
	 */

	texture = window->loadPicture("PauseButton.png");
}

PauseButton::PauseButton(SDL_Rect positionAndSize)
{
	effective = false;
	this->positionAndSize = positionAndSize;
}

void PauseButton::clickEvent(GameData *gameData)
{
	if (!gameData->pause)
		gameData->gameStatus = PAUSE;
	else
		gameData->gameStatus = GAMING;
	gameData->pause = !gameData->pause;
}

StartButton::StartButton(Window *window)
{
	effective = false;
	texture = window->loadPicture("StartButton.png");
	positionAndSize.x = 715;
	positionAndSize.y = 235;
	SDL_QueryTexture(texture, nullptr, nullptr, &positionAndSize.w, &positionAndSize.h);

}

StartButton::StartButton(SDL_Rect positionAndSize)
{
	effective = false;
	this->positionAndSize = positionAndSize;
}

void StartButton::clickEvent(GameData *gameData)
{
	gameData->gameStatus = GAMING;
	effective = false;
}

ExitButton::ExitButton(Window *window)
{
	effective = false;
	texture = window->loadPicture("ExitButton.png");
	SDL_QueryTexture(texture, nullptr, nullptr, &positionAndSize.w, &positionAndSize.h);
	positionAndSize.x = 1280 - positionAndSize.w;
	positionAndSize.y = 720 - positionAndSize.h;
}

ExitButton::ExitButton(SDL_Rect positionAndSize)
{
	effective = false;
	this->positionAndSize = positionAndSize;
}

void ExitButton::clickEvent(GameData *gameData)
{
	gameData->running = false;
}

UI::UI(Window *window)
		: mainMenuButtons{}, gamingButtons{}, pauseButtons{}, buttons{&mainMenuButtons, &gamingButtons, &pauseButtons}
{
	mainMenuButtons.push_back(new StartButton(window));
	mainMenuButtons.push_back(new ExitButton(window));
	for (auto button: mainMenuButtons)
		button->effective = true;
	gamingButtons.push_back(new PauseButton(window));
	pauseButtons.push_back(new ExitButton(window));
}


void UI::clickButton(int x, int y, GameData *gameData)
{
	SDL_Point mousePos = {x, y};
	for (auto button: mainMenuButtons)
		if (SDL_PointInRect(&mousePos, &button->positionAndSize) && button->effective)
			button->clickEvent(gameData);
}

void UI::showButton(Window *window, GameData *gameData)
{
	int currentStatus = gameData->gameStatus;
	switch (gameData->gameStatus)
	{
		case MAIN_MENU:
			for (auto button: mainMenuButtons)
			{
				button->effective = true;
				SDL_RenderCopy(window->getRenderer(), button->texture, nullptr, &button->positionAndSize);
			}
			break;
		case GAMING:
			break;
		case PAUSE:
			break;
	}
	if (currentStatus != gameData->gameStatus)
	{
		auto invalidButtons = buttons[currentStatus];
		for (auto button:*invalidButtons)
			button->effective = false;
		auto activeButtons = buttons[gameData->gameStatus];
		for (auto button:*activeButtons)
			button->effective = true;
	}
}

