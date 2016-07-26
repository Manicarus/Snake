/*
 * snake.h
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#ifndef SNAKE_H_
#define SNAKE_H_

typedef enum
{
	FALSE = 0,
	TRUE  = 1
} Bool;

typedef enum
{

} Color;

typedef enum
{

} Type;

typedef enum
{
	NORTH = 0,
	SOUTH = 1,
	EAST  = 2,
	WEST  = 3
} Dir;

typedef struct Snake
{
	struct cell *head;
	struct cell *body;
	float speed;
} Snake;

typedef struct Cell
{
	int x, y;

	Color color;
	Type  type;
	Dir   dir;

	struct cell *previous;
	struct cell *next;
} Cell;

typedef Cell Food;

int init();

int update();

int terminate();

Bool move();

void copy_cell(Cell target, Cell source);

void digest();

#endif /* SNAKE_H_ */
