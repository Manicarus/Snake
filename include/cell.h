/*
 * cell.h
 *
 *  Created on: 2016. 8. 6.
 *      Author: manicarus
 */

#ifndef CELL_H_
#define CELL_H_

enum Color
{
	RED,
	GREEN
};

struct Cell
{
	int x, y;
	enum Color color;
	struct Cell *previous, *next;
};

// public
struct Cell *c_create();
void c_kill(struct Cell *cell);
void c_link(struct Cell *cell_a, struct Cell *cell_b);

// private
static void set_x(struct Cell *cell, int x);
static void set_y(struct Cell *cell, int y);

static int get_x(struct Cell *cell);
static int get_y(struct Cell *cell);

#endif /* CELL_H_ */
