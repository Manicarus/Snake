#include "../include/apple.h"
#include <time.h>
#include <stdlib.h>

void apple_harvest(struct apple *self, struct boundary *world)
{
    self->juice = cell_create();

    srand(time(NULL));

    int random_x = apple_get_random_x(self, world);
    int random_y = apple_get_random_y(self, world);

    apple_set_x(self, random_x);
    apple_set_y(self, random_y);

    apple_set_color(self, RED);
}

bool apple_is_eaten(struct apple *self, struct snake *player)
{
    if(cell_is_overlapped(apple_squeeze(self), snake_get_head(player)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void apple_draw(struct apple *self)
{
    cell_draw(self->juice);
}

struct cell *apple_squeeze(struct apple *self)
{
        return self->juice;
}

static void apple_set_x(struct apple *self, int new_x)
{
    cell_set_x(self->juice, new_x);
}

static void apple_set_y(struct apple *self, int new_y)
{
    cell_set_y(self->juice, new_y);
}

static void apple_set_color(struct apple *self, ALLEGRO_COLOR new_color)
{
    cell_set_color(self->juice, new_color);
}

static int apple_get_h(struct apple *self)
{
    return cell_get_h(apple_squeeze(self));
}

static int apple_get_w(struct apple *self)
{
    return cell_get_w(apple_squeeze(self));
}

static int apple_get_random_x(struct apple *self, struct boundary *world)
{
    return (rand() % (boundary_get_w(world) / apple_get_w(self))) * apple_get_w(self);
}

static int apple_get_random_y(struct apple *self, struct boundary *world)
{
    return (rand() % (boundary_get_h(world) / apple_get_h(self))) * apple_get_h(self);
}
