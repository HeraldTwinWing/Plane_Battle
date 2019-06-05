//
// Created by Avala on 2019/5/29.
//

#include "UI.h"

Button::Button()=default;

PauseButton::PauseButton(Window *window)
{
	effective = false;
	/*
	positionAndSize.x = ;
	positionAndSize.y = y;
	positionAndSize.h = h;
	positionAndSize.w = w;
	 */

	texture = window->load_picture("PauseButton.png");
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
	texture = window->load_picture("StartButton.png");
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

ExitButton::ExitButton(int x, int y, int w, int h, Window *window)
{
	effective = false;
	texture = window->load_picture("ExitButton.png");
	positionAndSize.x = x;
	positionAndSize.y = y;
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
{
 	buttons.push_back(new StartButton(window));
	buttons[0]->effective = true;
}


void UI::clickButton(int x, int y, GameData *gameData)
{
    SDL_Point mousePos = {x, y};
    for (auto button: buttons)
        if (SDL_PointInRect(&mousePos, &button->positionAndSize) && button->effective)
	        button->clickEvent(gameData);
}

void UI::showButton(Window *window)
{
    for (auto button: buttons)
        if (button->effective)
            SDL_RenderCopy(window->getRenderer(), button->texture, nullptr, &button->positionAndSize);
}

