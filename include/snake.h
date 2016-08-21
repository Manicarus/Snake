/*
 * snake.h
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include "cell.h"

struct init_set_val;

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct snake
{
	struct Cell *head;

	float speed;
};

struct snake create_snake();

void destory_snake();

int snk_init(struct snake *snake);

void snk_grow(struct snake *snake, struct cell *new_cell);

void snk_move(struct snake *snake, int delta_x, int delta_y);

#endif /* SNAKE_H_ */
