/*
 * game.h
 *
 *  Created on: 2016. 8. 7.
 *      Author: manicarus
 */

#ifndef GAME_H_
#define GAME_H_

enum game_state;

void create_game();

void init_game(struct game *game);

void update_game(struct game *game);

void render_game();

void release_game(struct game *game);

int is_game_over();

#endif /* GAME_H_ */
