#include "../include/staff.h"

int stf_init_all(struct Staff *staff)
{
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    stf_init_event_queue(staff);
    stf_init_display_default(staff);
    stf_init_input(staff);
    stf_init_timer(staff);

    return 0;
}

int stf_init_display_default(struct Staff *staff)
{
    return stf_init_display(staff, DISPLAY_W, DISPLAY_H);
}

int stf_init_display(struct Staff *staff, int w, int h)
{
    staff->display = al_create_display(w, h);
    if(!(staff->display)) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    if(!(staff->event_queue))
    {
        fprintf(stderr, "display: failed to register event source!\n");
        return -1;
    }

    al_register_event_source(
        staff->event_queue,
        al_get_display_event_source(staff->display)
    );

    return 0;
}

int stf_init_input(struct Staff *staff)
{
    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    if(!(staff->event_queue))
    {
        fprintf(stderr, "keyboard: failed to register event source!\n");
        return -1;
    }

    al_register_event_source(
        staff->event_queue,
        al_get_keyboard_event_source()
    );

    return 0;
}

int stf_init_timer(struct Staff *staff)
{
    staff->timer = al_create_timer(1.0 / FPS);
    if(!(staff->timer)) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }


    if(!(staff->event_queue))
    {
        fprintf(stderr, "timer: failed to register event source!\n");
        return -1;
    }

    al_register_event_source(
        staff->event_queue,
        al_get_timer_event_source(staff->timer)
    );

    return 0;
}

int stf_init_event_queue(struct Staff *staff)
{
    staff->event_queue = al_create_event_queue();
    if(!(staff->event_queue)) {
        fprintf(stderr, "failed to create event_queue!\n");
        return -1;
    }

    return 0;
}

void stf_get_event(struct Staff *staff, )
{

}

void stf_destroy_all(struct Staff *staff)
{
    if(staff->display)
    {
        al_destroy_display(staff->display);
    }

    if(staff->timer)
    {
        al_destroy_timer(staff->timer);
    }

    if(staff->event_queue)
    {
        al_destroy_event_queue(staff->event_queue);
    }
}
