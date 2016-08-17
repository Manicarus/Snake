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

struct snake
{
	struct cell *head;

	float speed;

	static int (*init)(struct snake *snake);
	static void (*grow)(struct snake *snake, struct cell *new_cell);
	static void (*move)(struct snake *snake, int delta_x, int delta_y);
};

struct snake create_snake()
{
	struct snake *new_snake;
	new_snake = malloc(sizeof(struct snake));

	new_snake->init = init_snake;

	return
}

static int init_snake(struct snake *snake)
{
	int i;
	struct cell new_cell;

	for(i = 0; i < 3; i++)
	{
		new_cell = create_cell(INIT_HEAD_X, INIT_HEAD_Y + i);
		grow_snake(snake, new_cell);
	}

	snake->speed = INIT_SPEED;

	snake->grow = grow_snake;
	snake->move = move_snake;

	return 0;
}

static void grow_snake(struct snake *snake, struct cell *new_cell)
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


static void move_snake(struct snake *snake, int delta_x, int delta_y)
{
	struct cell *new_head = snake->head->previous;

	int new_head_x = snake->head->x + delta_x;
	int new_head_y = snake->head->y + delta_y;

	place_cell(new_head, new_head_x, new_head_y);

	snake->head = new_head;
}
