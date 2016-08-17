/*
 * snake.h
 *
 *  Created on: 2016. 7. 26.
 *      Author: manicarus
 */

#ifndef SNAKE_H_
#define SNAKE_H_

struct init_set_val;

struct snake;

struct snake create_snake();

static void destory_snake();

static int init_snake(struct snake *snake);

static void grow_snake(struct snake *snake, struct cell *new_cell);

static void move_snake(struct snake *snake, int delta_x, int delta_y);

#endif /* SNAKE_H_ */
