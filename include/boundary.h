#ifndef BOUNDARY_H_
#define BOUNDARY_H_

#define BOUNDARY_INIT_COLOR  al_map_rgb(  0,   0, 255)
#define BOUNDARY_PADDING 1

struct boundary
{
    int top_left_x;
    int top_left_y;
    int btm_right_x;
    int btm_right_y;

    ALLEGRO_COLOR color;
};

void boundary_init(
    struct boundary *self,
    int top_left_x,
    int top_left_y,
    int bottom_right_x,
    int bottom_right_y
);

void boundary_draw(struct boundary *self);

int boundary_get_w(struct boundary *self);

int boundary_get_h(struct boundary *self);

int boundary_get_top_left_x(struct boundary *self);

int boundary_get_top_left_y(struct boundary *self);

int boundary_get_btm_right_x(struct boundary *self);

int boundary_get_btm_right_y(struct boundary *self);

#endif
