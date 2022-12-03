/*
	Author: TNTExplosion

	The idea of this project is to learn more about SDL and c++



	- Twitter: @TNTrinitroto
	- Github: https://github.com/ExplosionTNT
	- StackOverflow: https://stackoverflow.com/users/20402414/tnt
	- Itch.io: https://tnt-explosion.itch.io/
*/


// Headers
#include "game/game.hpp"


int main(int argc, char *argv[]) {
	Game &game = Game::get();
	game.run();
	return 0;
}