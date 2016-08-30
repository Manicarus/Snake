#include "../include/score.h"
#include <stdlib.h>
#include <string.h>

void score_init(struct score *self, int center_x, int center_y)
{
    self->value = 0;
    self->label = self->label = malloc(sizeof(char) * 20);
    self->font = al_load_ttf_font("CONTFO__.ttf", 20, ALLEGRO_TTF_MONOCHROME);
    self->center_x = center_x;
    self->center_y = center_y;
}

void score_add(struct score *self, struct snake *player, enum action reward)
{
    self->value += reward * snake_get_length(player);
}

void score_draw(struct score *self)
{
    char buffer[10];

    strcpy(self->label, SCORE_LABEL);
    snprintf(buffer, 10, "%d", self->value);
    strcat(self->label, buffer);

    al_draw_text(
        self->font,
        GREEN,
        self->center_x,
        self->center_y,
        ALLEGRO_ALIGN_CENTRE,
        self->label
    );
}

void score_release(struct score *self)
{
    if(self->label)
    {
        free(self->label);
    }

    if(self->font)
    {
        al_destroy_font(self->font);
    }
}

int score_get_value(struct score *self)
{
    return self->value;
}
