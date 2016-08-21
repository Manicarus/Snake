/*
 * cell.c
 *
 *  Created on: 2016. 8. 6.
 *      Author: manicarus
 */

#include "../include/cell.h"
#include <stdlib.h>
#include <stdio.h>

struct Cell *c_create()
{
	struct Cell *new_cell;

	new_cell = malloc(sizeof(struct Cell));
	if(!new_cell)
	{
		perror("Failed to create a new cell!\n");
	}

	return new_cell;
}

void c_destroy(struct Cell *cell)
{
	free(cell);
}

void c_link(struct Cell *cell_a, struct Cell *cell_b)
{

}

void c_move(struct Cell *cell, int delta_x, int delta_y)
{
	// cell->x += delta_x;
	// cell->y += delta_y;
	set_x(cell, get_x(cell) + delta_x);
	set_y(cell, get_y(cell) + delta_y);
}

static void set_x(struct Cell *cell, int x)
{

}

static void set_y(struct Cell *cell, int y)
{

}

static int get_x(struct Cell *cell)
{

}

static int get_y(struct Cell *cell)
{

}
