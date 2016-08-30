/*
 * snake.c
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#include "../include/snake.h"

int snake_init(struct snake *self, int head_x, int head_y)
{
	struct cell *new_cell;

	self->head = NULL;

	snake_set_speed(self, SNAKE_INIT_SPEED);
	snake_set_direction(self, SNAKE_INIT_DIRECTION);
	snake_set_length(self, 0);

	while(snake_get_length(self) < SNAKE_INIT_LENGTH)
	{
		new_cell = cell_create();
		cell_init_default(new_cell);

		cell_set_x(new_cell, head_x);
		cell_set_y(new_cell, head_y
			+ snake_get_length(self)
			* snake_get_unit_move_y(self)
		);

		snake_grow(self, new_cell);
	}

	return 0;
}

void snake_grow(struct snake *self, struct cell *new_cell)
{
	struct cell *next_cell, *prev_cell;

	cell_set_color(new_cell, GREEN);

	if(!(self->head))
	{
		self->head = new_cell;

		self->head->next     = self->head;
		self->head->previous = self->head;
	}
	else
	{
		next_cell = self->head;
		prev_cell = self->head->previous;

		new_cell->next     = next_cell;
		new_cell->previous = prev_cell;

		next_cell->previous = new_cell;
		prev_cell->next     = new_cell;

		self->head = new_cell;
	}

	snake_set_length(self, (snake_get_length(self) + 1));
	//self->length++;
}

void snake_kill(struct snake *self)
{

}

void snake_draw(struct snake *self)
{
	struct cell* index = self->head;

	do
	{
		cell_draw(index);
		index = index->next;
	}
	while(index != self->head);
}

void snake_move(struct snake *self, enum direction dir)
{
	struct cell *new_head = self->head->previous;

	int new_head_x;
	int new_head_y;

	if(dir == UP)
	{
		new_head_x = self->head->x;
		new_head_y = self->head->y - snake_get_unit_move_y(self);
	}
	else if(dir == DOWN)
	{
		new_head_x = self->head->x;
		new_head_y = self->head->y + snake_get_unit_move_y(self);
	}
	else if(dir == LEFT)
	{
		new_head_x = self->head->x - snake_get_unit_move_x(self);
		new_head_y = self->head->y;
	}
	else if(dir == RIGHT)
	{
		new_head_x = self->head->x + snake_get_unit_move_x(self);
		new_head_y = self->head->y;
	}

	cell_set_x(new_head, new_head_x);
	cell_set_y(new_head, new_head_y);

	self->head = new_head;
}

void snake_set_speed(struct snake *self, float new_speed)
{
	self->speed = new_speed;
}

float snake_get_speed(struct snake *self)
{
	return self->speed;
}

int snake_get_unit_move_x(struct snake *self)
{
	return cell_get_w();
}

int snake_get_unit_move_y(struct snake *self)
{
	return cell_get_h();
}

struct cell *snake_get_head(struct snake *self)
{
	return self->head;
}

void snake_set_direction(struct snake *self, enum direction new_dir)
{
	self->dir = new_dir;
}

enum direction snake_get_direction(struct snake *self)
{
	return self->dir;
}

int snake_get_length(struct snake *self)
{
	return self->length;
}

void snake_set_length(struct snake *self, int new_length)
{
	self->length = new_length;
}

bool snake_is_bounded(
	struct snake *self,
	struct boundary *world
)
{
	struct cell* index = self->head;

	do
	{
		if(!cell_is_bounded(index, world))
		{
			return false;
		}
		index = index->next;
	}
	while(index != self->head);

	return true;
}

bool snake_is_self_bumped(struct snake *self)
{
	struct cell *index = self->head->next;

	do
	{
		if(cell_is_overlapped(self->head, index))
		{
			return true;
		}
		index = index->next;
	}
	while(index != self->head);

	return false;
}
