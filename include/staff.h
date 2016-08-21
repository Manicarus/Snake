#ifndef STAFF_H_
#define STAFF_H_

#include <allegro.h>

enum Setting
{
	DISPLAY_W = 640,
	DISPLAY_H = 480,
	FPS       = 60
};

struct Staff
{
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE *event_queue;
};

int stf_init_all(struct Staff *staff);

int stf_init_display_default(struct Staff *staff);

int stf_init_display(struct Staff *staff, int w, int h);

int stf_init_input(struct Staff *staff);

int stf_init_timer(struct Staff *staff);

int stf_init_event_queue(struct Staff *staff);

void stf_destroy_all(struct Staff *staff);

#endif
