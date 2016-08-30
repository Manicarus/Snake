/*
 * cell.h
 *
 *  Created on: 2016. 8. 6.
 *      Author: manicarus
 */

#ifndef CELL_H_
#define CELL_H_

#include <allegro.h>
#include "boundary.h"

#define CELL_INIT_W 20
#define CELL_INIT_H 20

#define CELL_INIT_X 0
#define CELL_INIT_Y 0

#define CELL_PADDING 2

#define RED   al_map_rgb(255,   0,   0)
#define GREEN al_map_rgb(  0, 255,   0)
#define BLUE  al_map_rgb(  0,   0, 255)

#define CELL_INIT_COLOR GREEN

struct cell
{
	int x, y;
	ALLEGRO_COLOR color;
	struct cell *previous, *next;
};

struct cell *cell_create();
void cell_destroy(struct cell *self);

void cell_init_default(struct cell* self);

void cell_draw(struct cell *self);

void cell_set_x(struct cell *self, int new_x);
void cell_set_y(struct cell *self, int new_y);

int cell_get_x(struct cell *self);
int cell_get_y(struct cell *self);

void cell_set_w(int new_cell_w);
void cell_set_h(int new_cell_h);

int cell_get_w();
int cell_get_h();

void cell_set_color(struct cell *self, ALLEGRO_COLOR new_color);

bool cell_is_overlapped(struct cell *self, struct cell *trial);

bool cell_is_bounded(struct cell *self, struct boundary *world);

#endif /* CELL_H_ */
