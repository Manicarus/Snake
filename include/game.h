/*
 * game.h
 *
 *  Created on: 2016. 8. 7.
 *      Author: manicarus
 */

#ifndef GAME_H_
#define GAME_H_

#include "snake.h"
#include "staff.h"

enum GameState
{
	GAME_OVER = 0
};

struct Game
{
	struct Snake snake;
	struct Staff staff;
    enum GameState game_state;
};

void gm_init(struct Game *game);

void gm_update(struct Game *game);

void gm_render(struct Game *game);

void gm_release(struct Game *game);

int is_game_over(struct Game *game);

#endif /* GAME_H_ */
