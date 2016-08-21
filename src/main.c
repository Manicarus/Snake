/*
 * main.c
 *
 *  Created on: 2016. 7. 24.
 *      Author: manicarus
 */

#include "../include/game.h"

int main()
{
	struct Game game;

	gm_init(&game);

	while(!is_game_over())
	{
		gm_update(&game);
		gm_render(&game);
	}

	gm_release(&game);

	return 0;
}
