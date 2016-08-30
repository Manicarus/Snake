/*
 * main.c
 *
 *  Created on: 2016. 7. 24.
 *      Author: manicarus
 */

#include "../include/game.h"
#include <allegro_font.h>
#include <allegro_ttf.h>

// TODO: organize gameflow
int main()
{
    struct game game;

    game_init(&game);

    while(game_get_state(&game) != EXIT)
    {
        game_update(&game);
        game_render(&game);

        if(game_get_state(&game) == GAME_OVER)
        {
            // al_clear_to_color(al_map_rgb(0,0,0));
            // al_load_ttf_font() 함수를 al_destroy_font()를 호출하지 않고
            // 무한 반복해서 호출하면 segmentation fault가 발생한다.
            al_draw_text(
                al_load_ttf_font("CONTFO__.ttf", 100, ALLEGRO_TTF_MONOCHROME),
                al_map_rgb(0, 255, 0),
                320,
                170,
                ALLEGRO_ALIGN_CENTRE,
                "GAME OVER"
            );

            al_draw_text(
                al_load_ttf_font("CONTFO__.ttf", 50, ALLEGRO_TTF_MONOCHROME),
                al_map_rgb(0, 255, 0),
                200,
                300,
                ALLEGRO_ALIGN_CENTRE,
                "RETRY"
            );

            al_draw_text(
                al_load_ttf_font("CONTFO__.ttf", 50, ALLEGRO_TTF_MONOCHROME),
                al_map_rgb(0, 255, 0),
                440,
                300,
                ALLEGRO_ALIGN_CENTRE,
                "EXIT"
            );

            al_flip_display();

            while(game_get_state(&game) == GAME_OVER);
        }
    }

    game_release(&game);

    return 0;
}
