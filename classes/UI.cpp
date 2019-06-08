//
// Created by Avala on 2019/5/29.
//

#include "UI.h"

PauseButton::PauseButton(Window *window)
{
	texture = window->loadPicture("PauseButton.png");
	effective = false;
	SDL_QueryTexture(texture, nullptr, nullptr, &positionAndSize.w, &positionAndSize.h);
	positionAndSize.x = 1280 - positionAndSize.w;
	positionAndSize.y = 0;
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

void StartButton::clickEvent(GameData *gameData)
{
	gameData->gameStatus = GAMING;
	gameData->startTime = SDL_GetTicks();
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

void ExitButton::clickEvent(GameData *gameData)
{
	gameData->running = false;
}

void UI::clickButton(int x, int y, GameData *gameData)
{
	SDL_Point mousePos = {x, y};
	for (auto button: *buttons[gameData->gameStatus])
		if (SDL_PointInRect(&mousePos, &button->positionAndSize) && button->effective)
			button->clickEvent(gameData);
}

ContinueButton::ContinueButton(Window *window)
{
	texture = window->loadPicture("Continue.png");
	effective = false;
	SDL_QueryTexture(texture, nullptr, nullptr, &positionAndSize.w, &positionAndSize.h);
	positionAndSize.x = 0;
	positionAndSize.y = 720 - positionAndSize.h;
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
	pauseButtons.push_back(new ContinueButton(window));
}


void ContinueButton::clickEvent(GameData *gameData)
{
	gameData->gameStatus = GAMING;
}

void UI::refreshUI(Window *window, GameData *gameData)
{
	int currentStatus = gameData->gameStatus;

	//激活并显示按钮
	switch (gameData->gameStatus)
	{
		case MAIN_MENU:
			for (auto &button: mainMenuButtons)
			{
				button->effective = true;
				SDL_RenderCopy(window->getRenderer(), button->texture, nullptr, &button->positionAndSize);
			}
			break;
		case GAMING:
			for (auto &button: gamingButtons)
			{
				button->effective = true;
				SDL_RenderCopy(window->getRenderer(), button->texture, nullptr, &button->positionAndSize);
			}
			break;
		case PAUSE:
			for (auto &button: pauseButtons)
			{
				button->effective = true;
				SDL_RenderCopy(window->getRenderer(), button->texture, nullptr, &button->positionAndSize);
			}
			break;
	}

	// 游戏状态发生变化时将当前界面的按钮无效化
	if (currentStatus != gameData->gameStatus)
	{
		auto invalidButtons = buttons[currentStatus];
		for (auto button:*invalidButtons)
			button->effective = false;
	}
}
