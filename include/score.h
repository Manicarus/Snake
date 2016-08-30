#ifndef SCORE_H_
#define SCORE_H_

#include <allegro_font.h>
#include <allegro_ttf.h>
#include "snake.h"

#define SCORE_LABEL "SCORE: "

enum action
{
    MOVING = 1,
    EATING = 20
};

struct score
{
    int value;
    char *label;
    ALLEGRO_FONT *font;
    int center_x, center_y;
};

void score_init(struct score *self, int center_x, int center_y);

void score_add(struct score *self, struct snake *player, enum action reward);

void score_draw(struct score *self);

int score_get_value(struct score *self);

void score_release(struct score *self);

#endif
