#ifndef APPLE_H_
#define APPLE_H_

#include <allegro.h>
#include "snake.h"

enum apple_state
{
    fresh,
    rotten
};

struct apple
{
	struct cell *juice;
};

void apple_harvest(struct apple *self, struct boundary *world);

bool apple_is_eaten(struct apple *self, struct snake *player);

void apple_draw(struct apple *self);

struct cell *apple_squeeze(struct apple *self);

static void apple_set_x(struct apple *self, int new_x);
static void apple_set_y(struct apple *self, int new_y);

static int apple_get_x(struct apple *self);
static int apple_get_y(struct apple *self);

static void apple_set_color(struct apple *self, ALLEGRO_COLOR new_color);

static int apple_get_w(struct apple *self);
static int apple_get_h(struct apple *self);

static int apple_get_random_x(struct apple *self, struct boundary *world);
static int apple_get_random_y(struct apple *self, struct boundary *world);

#endif
