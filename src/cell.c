/*
 * cell.c
 *
 *  Created on: 2016. 8. 6.
 *      Author: manicarus
 */

#include "../include/cell.h"
#include <stdlib.h>
#include <stdio.h>

struct cell *create_cell()
{
	struct cell *new_cell;
	new_cell = malloc(sizeof(struct cell));

	if(!new_cell)
	{
		perror("failed to create a new cell!\n");
	}

	new_cell->init    = init_cell;
	new_cell->destroy = destroy_cell;
	new_cell->move    = move_cell;
	new_cell->place   = place_cell;

	return new_cell;
}

static void destroy_cell(struct cell *cell)
{
	free(cell);
}

static void init_cell(struct cell *cell, int x, int y)
{
	cell->x = x;
	cell->y = y;
}

static void move_cell(struct cell *cell, int delta_x, int delta_y)
{
	cell->x += delta_x;
	cell->y += delta_y;
}

static void place_cell(struct cell *cell, int x, int y)
{
	cell->x = x;
	cell->y = y;
}
