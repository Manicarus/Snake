/*
 * game.h
 *
 *  Created on: 2016. 8. 7.
 *      Author: manicarus
 */

#ifndef GAME_H_
#define GAME_H_

#include <allegro.h>
#include "snake.h"
#include "boundary.h"
#include "score.h"
#include "apple.h"

#define GAME_INIT_DISPLAY_W 640
#define GAME_INIT_DISPLAY_H 480
#define GAME_INIT_FPS  20
#define GAME_INPUT_NUM 5
#define GAME_MAX_APPLE_NUM 10

enum game_state
{
	GAME_OVER,
	PLAYING,
	EXIT
};

enum key_code
{
	KEY_UP = 0,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_PAUSE,
	KEY_ENTER
};

struct game
{
	struct snake player;
	struct boundary world;
	struct score board;
	struct apple treat;

	enum game_state state;

	bool key[GAME_INPUT_NUM];
	bool is_game_over;

	int display_w;
	int display_h;
	int fps;

	ALLEGRO_BITMAP *boundary;
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *fps_timer;
	ALLEGRO_TIMER *player_timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
};

int game_init(struct game *self);

void game_update(struct game *self);

void game_render(struct game *self);

void game_release(struct game *self);

void game_set_display_w(struct game *self, int w);

void game_set_display_h(struct game *self, int h);

int game_get_display_w(struct game *self);

int game_get_display_h(struct game *self);

void game_set_fps(struct game *self, float new_fps);

float game_get_fps(struct game *self);

void game_set_state(struct game *self, enum game_state state);

enum game_state game_get_state(struct game *self);

void game_clear_key(struct game *self);

#endif /* GAME_H_ */
