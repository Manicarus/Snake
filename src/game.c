/*
 * game.c
 *
 *  Created on: 2016. 8. 7.
 *      Author: manicarus
 */

#include "../include/game.h"
#include <allegro_font.h>
#include <allegro_ttf.h>
#include <allegro_primitives.h>

int game_init(struct game *self)
{
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	game_set_display_w(self, GAME_INIT_DISPLAY_W);
	game_set_display_h(self, GAME_INIT_DISPLAY_H);
	game_set_fps(self, GAME_INIT_FPS);
	game_set_state(self, PLAYING);
	game_clear_key(self);

	self->display = al_create_display(
		game_get_display_w(self),
		game_get_display_h(self)
	);

    if(!(self->display))
	{
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

	self->fps_timer = al_create_timer(1.0 / game_get_fps(self));
    if(!(self->fps_timer))
	{
        fprintf(stderr, "failed to create fps timer!\n");
        return -1;
    }

	self->event_queue = al_create_event_queue();
    if(!(self->event_queue))
	{
	    fprintf(stderr, "failed to create event_queue!\n");
	    return -1;
	}

	if(!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	snake_init(
		&(self->player),
		(game_get_display_w(self) / 2),
		(game_get_display_h(self) / 2)
	);

	self->player_timer = al_create_timer(1.0 / snake_get_speed(&(self->player)));
	if(!(self->player_timer)) {
		fprintf(stderr, "failed to create player speed timer!\n");
		return -1;
	}

	al_register_event_source(
        self->event_queue,
        al_get_display_event_source(self->display)
    );

	al_register_event_source(
        self->event_queue,
        al_get_timer_event_source(self->fps_timer)
    );

	al_register_event_source(
		self->event_queue,
		al_get_keyboard_event_source()
	);

	al_register_event_source(
		self->event_queue,
		al_get_timer_event_source(self->player_timer)
	);

	boundary_init(
		&(self->world),
		0,
		0,
		self->display_h,
		self->display_h
	);

	score_init(
		&(self->board),
		(self->display_w + self->display_h) / 2,
		self->display_h / 20
	);

	apple_harvest(&(self->treat), &(self->world));

	al_start_timer(self->fps_timer);
    al_start_timer(self->player_timer);

	return 0;
}

void game_update(struct game *self)
{
	ALLEGRO_EVENT ev;
	al_wait_for_event(self->event_queue, &ev);

	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{

	}
	else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev.keyboard.keycode)
		{
		    case ALLEGRO_KEY_UP:
		        self->key[KEY_UP] = true;
		    	break;

		    case ALLEGRO_KEY_DOWN:
		        self->key[KEY_DOWN] = true;
		        break;

		    case ALLEGRO_KEY_LEFT:
		        self->key[KEY_LEFT] = true;
		        break;

		    case ALLEGRO_KEY_RIGHT:
		        self->key[KEY_RIGHT] = true;
		        break;
		}
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev.keyboard.keycode)
		{
            case ALLEGRO_KEY_UP:
            	self->key[KEY_UP] = false;
            	break;

            case ALLEGRO_KEY_DOWN:
            	self->key[KEY_DOWN] = false;
            	break;

            case ALLEGRO_KEY_LEFT:
            	self->key[KEY_LEFT] = false;
            	break;

            case ALLEGRO_KEY_RIGHT:
            	self->key[KEY_RIGHT] = false;
            	break;
         }
	}
	else if(ev.type == ALLEGRO_EVENT_TIMER) {
		if(ev.timer.source == self->fps_timer) {
	        if(self->key[KEY_UP]
				&& (snake_get_direction(&(self->player)) != DOWN)) {
	            snake_set_direction(&(self->player), UP);
	        }

			if(self->key[KEY_DOWN]
				&& (snake_get_direction(&(self->player)) != UP)) {
	            snake_set_direction(&(self->player), DOWN);
	        }

	        if(self->key[KEY_LEFT]
				&& (snake_get_direction(&(self->player)) != RIGHT)) {
	            snake_set_direction(&(self->player), LEFT);
	        }

			if(self->key[KEY_RIGHT]
				&& (snake_get_direction(&(self->player)) != LEFT)) {
	            snake_set_direction(&(self->player), RIGHT);
	        }
		}
		else if(ev.timer.source == self->player_timer)
		{
			if(snake_get_direction(&(self->player)) == UP)
			{
				snake_move(&(self->player), UP);
			}
			else if(snake_get_direction(&(self->player)) == DOWN)
			{
				snake_move(&(self->player), DOWN);
			}
			else if(snake_get_direction(&(self->player)) == LEFT)
			{
				snake_move(&(self->player), LEFT);
			}
			else if(snake_get_direction(&(self->player)) == RIGHT)
			{
				snake_move(&(self->player), RIGHT);
			}

			if(!snake_is_bounded(&(self->player), &(self->world))
			|| (snake_is_self_bumped(&(self->player))))
			{
				game_set_state(self, GAME_OVER);
			}

			if(apple_is_eaten(&(self->treat), &(self->player)))
			{
				snake_grow(&(self->player), apple_squeeze(&(self->treat)));
				apple_harvest(&(self->treat), &(self->world));
			}

			score_add(&(self->board), &(self->player), MOVING);
		}
    }
}

void game_render(struct game *self)
{
	al_clear_to_color(al_map_rgb(0,0,0));

	snake_draw(&(self->player));
	boundary_draw(&(self->world));
	score_draw(&(self->board));
	apple_draw(&(self->treat));

	al_flip_display();
}

void game_release(struct game *self)
{
	if(self->display)
    {
        al_destroy_display(self->display);
    }

    if(self->fps_timer)
    {
        al_destroy_timer(self->fps_timer);
    }

	if(self->player_timer)
    {
        al_destroy_timer(self->player_timer);
    }

    if(self->event_queue)
    {
        al_destroy_event_queue(self->event_queue);
    }

	score_release(&(self->board));
}

void game_set_display_w(struct game *self, int new_display_w)
{
	self->display_w = new_display_w;
}

void game_set_display_h(struct game *self, int new_display_h)
{
	self->display_h = new_display_h;
}

int game_get_display_w(struct game *self)
{
	return self->display_w;
}

int game_get_display_h(struct game *self)
{
	return self->display_h;
}

void game_set_fps(struct game *self, float new_fps)
{
	self->fps = new_fps;
}

float game_get_fps(struct game *self)
{
	return self->fps;
}

void game_set_state(struct game *self, enum game_state state)
{
	self->state = state;
}

enum game_state game_get_state(struct game *self)
{
	return self->state;
}

void game_clear_key(struct game *self)
{
	int i;
	for(i = 0; i < GAME_INPUT_NUM; i++)
	{
		self->key[i] = false;
	}
}
