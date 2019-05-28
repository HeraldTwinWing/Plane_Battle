#include "classes/Game.h"

int main(int argc, char *args[])
{
	GameData game_data;
    Game game(&game_data);
    game.OnExecute();

    return 0;
}