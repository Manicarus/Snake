/*
 * snake.c
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#include "snake.h"

static Snake snake;
static Food  food;

// TODO:
// 1. Think of better name for the function
int game()
{
	init();

	while(TRUE)
	{
		update();
	}

	terminate();

	return 0;
}

int init()
{
	Cell *head, *body, *tail;

	head = malloc(sizeof(Cell));
	if(!head)
	{
		return -1;
	}

	body = malloc(sizeof(Cell));
	if(!body)
	{
		return -2;
	}

	tail = malloc(sizeof(Cell));
	if(!tail)
	{
		return -3;
	}

	head->next     = body;
	head->previous = tail;

	body->next     = tail;
	body->previous = head;

	tail->next     = head;
	tail->previous = body;

	snake.head = head;
	snake.body = body;

	return 0;
}

int update()
{
	move();
	digest();

	return 0;
}

// TODO:
// 1. Move head
// 2. Take keyboard input
Bool move()
{
	Cell *head = snake.head;
	Cell *index = head->previous;

	while(index != head)
	{
		copy_cell(index, index->previous);
		index = index->previous;
	}

}

void digest()
{

}
