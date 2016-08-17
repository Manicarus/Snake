/*
 * game.c
 *
 *  Created on: 2016. 8. 7.
 *      Author: manicarus
 */

#include "game.h"
#include "allegro.h"

enum INITIAL_GAME_SETTING
{
	DISPLAY_W = 640,
	DISPLAY_H = 480,
	FPS       = 60
};

enum game_state
{
	GAME_OVER = 0
};

struct alleg
{
	ALLEGRO_DISPLAY     *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER       *timer;
};

struct game
{
	struct snake snake;
	struct alleg allegro_setup;

	enum game_state game_state;
};

void init_game(struct game *game)
{
	init_snake_game(game->snake_game);

	game->game_state = !GAME_OVER;

	// init allegro
	struct alleg *allegro_setup = game->allegro_setup;

	if(!al_init()) {
	    perror(stderr, "failed to initialize allegro!\n");
	}

	if(!al_install_keyboard()) {
	    perror(stderr, "failed to initialize the keyboard!\n");
	}

	allegro_setup->timer = al_create_timer(1.0 / FPS);
	if(!allegro_setup->timer) {
		fprintf(stderr, "failed to create timer!\n");
	}

	allegro_setup->display = al_create_display(SCREEN_W, SCREEN_H);
	if(!allegro_setup->display) {
		al_destroy_timer(allegro_setup->timer);
		perror(stderr, "failed to create display!\n");
	}
}

void update_game(struct game *game)
{

}

void render_game()
{

}

void release_game(struct game *game)
{

}

int is_game_over(struct game *game)
{
	return !(game->game_state);
}
