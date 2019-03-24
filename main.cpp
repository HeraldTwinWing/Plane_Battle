#include <iostream>
#include "SDL2/SDL.h"

int main(int argc, char *args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	SDL_Window* main_window = SDL_CreateWindow("Plane Battle", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1280, 720,
		SDL_WINDOW_SHOWN);

	SDL_Delay(5000);
	SDL_DestroyWindow(main_window);

	SDL_Quit();
	return 0;
}