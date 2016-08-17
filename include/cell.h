/*
 * cell.h
 *
 *  Created on: 2016. 8. 6.
 *      Author: manicarus
 */

#ifndef CELL_H_
#define CELL_H_

struct cell
{
	int x, y;

	struct cell *previous, *next;

	void (*destroy)(struct cell *);
	void (*init   )(struct cell *, int, int);
	void (*move   )(struct cell *, int, int);
	void (*place  )(struct cell *, int, int);
};

struct cell *create_cell();

static void destroy_cell(struct cell *cell);

static void init_cell(struct cell *cell, int x, int y);

static void move_cell(struct cell *cell, int delta_x, int delta_y);

static void place_cell(struct cell *cell, int x, int y);

#endif /* CELL_H_ */
