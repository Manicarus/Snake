/*
 * cell.c
 *
 *  Created on: 2016. 8. 6.
 *      Author: manicarus
 */

#include "../include/cell.h"
#include <allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>

static int cell_w;
static int cell_h;

struct cell *cell_create()
{
	struct cell *new_cell;

	new_cell = malloc(sizeof(struct cell));
	if(!new_cell)
	{
		fprintf(stderr, "failed to create cell!\n");
		return NULL;
	}

	return new_cell;
}

void cell_init_default(struct cell* self)
{
	cell_set_x(self, CELL_INIT_X);
	cell_set_y(self, CELL_INIT_Y);

	cell_set_w(CELL_INIT_W);
	cell_set_h(CELL_INIT_H);

	cell_set_color(self, CELL_INIT_COLOR);
}

void cell_destroy(struct cell *self)
{
	free(self);
}

void cell_draw(struct cell *self)
{
	al_draw_filled_rectangle(
		cell_get_x(self) + CELL_PADDING,
		cell_get_y(self) + CELL_PADDING,
		(cell_get_x(self) + cell_get_w(self) - CELL_PADDING),
		(cell_get_y(self) + cell_get_h(self) - CELL_PADDING),
		self->color
	);

	// al_draw_rectangle(
	// 	display_x,
	// 	display_y,
	// 	(display_x + cell_get_w(self)),
	// 	(display_y + cell_get_h(self)),
	// 	self->color,
	// 	5
	// );
}

void cell_set_w(int new_cell_w)
{
	cell_w = new_cell_w;
}

void cell_set_h(int new_cell_h)
{
	cell_h = new_cell_h;
}

int cell_get_w()
{
	return cell_w;
}

int cell_get_h()
{
	return cell_h;
}

void cell_set_x(struct cell *self, int new_x)
{
	self->x = new_x;
}

void cell_set_y(struct cell *self, int new_y)
{
	self->y = new_y;
}

int cell_get_x(struct cell *self)
{
	return self->x;
}

int cell_get_y(struct cell *self)
{
	return self->y;
}

void cell_set_color(struct cell *self, ALLEGRO_COLOR new_color)
{
	self->color = new_color;
}

bool cell_is_overlapped(struct cell *self, struct cell *trial)
{
	if((cell_get_x(self) == cell_get_x(trial))
	&& (cell_get_y(self) == cell_get_y(trial)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cell_is_bounded(struct cell *self, struct boundary *world)
{
	if((cell_get_x(self) < boundary_get_top_left_x(world))
	|| (cell_get_x(self) >= boundary_get_btm_right_x(world))
	|| (cell_get_y(self) < boundary_get_top_left_y(world))
	|| (cell_get_y(self) >= boundary_get_btm_right_y(world)))
	{
		return false;
	}
	else
	{
		return true;
	}
}
