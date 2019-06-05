
#include "classes/Game.h"

int main(int argc, char *args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	GameData game_data;
	UI ui(game_data.mainWindow);
    Game game(&game_data, &ui);
    game.OnExecute();

	SDL_Quit();
    return 0;
}