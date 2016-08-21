/*
 * game.c
 *
 *  Created on: 2016. 8. 7.
 *      Author: manicarus
 */

#include "../include/game.h"


void gm_init(struct Game *game)
{
	stf_init_all(game->staff);
	snk_init(game->snake);
}

void gm_update(struct Game *game)
{
	ALLEGRO_EVENT ev;
	stf_get_event(game->staff, &ev);

	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{

	}
	else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev.keyboard.keycode)
		{
		    case ALLEGRO_KEY_UP:
		        key[KEY_UP] = true;
		    	break;

		    case ALLEGRO_KEY_DOWN:
		        key[KEY_DOWN] = true;
		        break;

		    case ALLEGRO_KEY_LEFT:
		        key[KEY_LEFT] = true;
		        break;

		    case ALLEGRO_KEY_RIGHT:
		        key[KEY_RIGHT] = true;
		        break;
		}
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev.keyboard.keycode)
		{
            case ALLEGRO_KEY_UP:
            	key[KEY_UP] = false;
            	break;

            case ALLEGRO_KEY_DOWN:
            	key[KEY_DOWN] = false;
            	break;

            case ALLEGRO_KEY_LEFT:
            	key[KEY_LEFT] = false;
            	break;

            case ALLEGRO_KEY_RIGHT:
            	key[KEY_RIGHT] = false;
            	break;
         }
	}
}

void gm_render()
{

}

void gm_release(struct Game *game)
{
	stf_destroy_all(game->staff);
}

int is_game_over(struct Game *game)
{

}
