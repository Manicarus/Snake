/*
 * snake.h
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <allegro.h>
#include "cell.h"
#include "boundary.h"

#define SNAKE_INIT_SPEED 15.0
#define SNAKE_INIT_DIRECTION DOWN
#define SNAKE_INIT_LENGTH 3

enum direction
{
	UP = 0, DOWN, LEFT, RIGHT
};

struct snake
{
	struct cell *head;

	enum direction dir;

	float speed;

	int length;
};

int snake_init(struct snake *self, int head_x, int head_y);

void snake_grow(struct snake *self, struct cell *new_cell);

void snake_kill(struct snake *self);

void snake_move(struct snake *self, enum direction dir);

void snake_draw(struct snake *self);

int snake_get_unit_move_x(struct snake *self);

int snake_get_unit_move_y(struct snake *self);

void snake_set_speed(struct snake *self, float new_speed);

float snake_get_speed(struct snake *self);

struct cell *snake_get_head(struct snake *self);

void snake_set_direction(struct snake *self, enum direction new_dir);

enum direction snake_get_direction(struct snake *self);

int snake_get_length(struct snake *self);

void snake_set_length(struct snake *self, int new_length);

bool snake_is_bounded(
	struct snake *self,
	struct boundary *world
);

bool snake_is_self_bumped(struct snake *self);

#endif /* SNAKE_H_ */
