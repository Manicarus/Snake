#include <allegro_primitives.h>
#include "../include/boundary.h"

void boundary_init(
    struct boundary *self,
    int top_left_x,
    int top_left_y,
    int btm_right_x,
    int btm_right_y
)
{
    self->top_left_x = top_left_x;
    self->top_left_y = top_left_y;
    self->btm_right_x = btm_right_x;
    self->btm_right_y = btm_right_y;

    self->color = BOUNDARY_INIT_COLOR;
}

void boundary_draw(struct boundary *self)
{
    al_draw_rectangle(
    	self->top_left_x + BOUNDARY_PADDING,
    	self->top_left_y + BOUNDARY_PADDING,
    	self->btm_right_x - BOUNDARY_PADDING,
    	self->btm_right_y - BOUNDARY_PADDING,
    	self->color,
    	5
    );
}

int boundary_get_w(struct boundary *self)
{
    return (self->btm_right_x - self->top_left_x);
}

int boundary_get_h(struct boundary *self)
{
    return (self->btm_right_y - self->top_left_y);
}

int boundary_get_w(struct boundary *self);

int boundary_get_h(struct boundary *self);

int boundary_get_top_left_x(struct boundary *self)
{
    return self->top_left_x;
}

int boundary_get_top_left_y(struct boundary *self)
{
    return self->top_left_y;
}

int boundary_get_btm_right_x(struct boundary *self)
{
    return self->btm_right_x;
}

int boundary_get_btm_right_y(struct boundary *self)
{
    return self->btm_right_y;
}
