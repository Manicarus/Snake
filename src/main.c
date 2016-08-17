/*
 * main.c
 *
 *  Created on: 2016. 7. 24.
 *      Author: manicarus
 */

#include <stdio.h>
#include "game.h"

int main()
{
	struct game game;

	init(game);

	while(!is_game_over())
	{
		update();
		render();
	}

	release();

	return 0;
}
