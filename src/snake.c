/*
 * snake.c
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#include "snake.h"

enum INITIAL_SNAKE_SETTING
{
	INIT_HEAD_X = 320,
	INIT_HEAD_Y = 240,
	INIT_SPEED  = 1

};

int snk_init(struct snake *snake)
{
	int i;
	struct cell new_cell;

	for(i = 0; i < 3; i++)
	{
		new_cell = create_cell(INIT_HEAD_X, INIT_HEAD_Y + i);
		grow_snake(snake, new_cell);
	}

	snake->speed = INIT_SPEED;

	return 0;
}

void snk_grow(struct snake *snake, struct cell *new_cell)
{
	struct cell *next_cell, *prev_cell;

	if(!(snake->head))
	{
		snake->head = new_cell;

		snake->head->next     = snake->head;
		snake->head->previous = snake->head;
	}
	else
	{
		next_cell = snake->head;
		prev_cell = snake->head->previous;

		new_cell->next     = next_cell;
		new_cell->previous = prev_cell;

		next_cell->previous = new_cell;
		prev_cell->next     = new_cell;

		snake->head = new_cell;
	}
}

void snk_move(struct snake *snake, enum direction dir)
{
	struct cell *new_head = snake->head->previous;

	// int new_head_x = snake->head->x + delta_x;
	// int new_head_y = snake->head->y + delta_y;



	place_cell(new_head, new_head_x, new_head_y);

	snake->head = new_head;
}
