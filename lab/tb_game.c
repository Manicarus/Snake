#include "../include/game.h"
#include <allegro_font.h>
#include <allegro_ttf.h>

int main(int argc, char const *argv[]) {

    struct game game;

    game_init(&game);

    al_init_font_addon();
    al_init_ttf_addon();

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_start_timer(game.fps_timer);
    al_start_timer(game.player_timer);

    while(1)
    {
        game_update(&game);
        game_render(&game);

        if(game_is_game_over(&game))
        {
            al_clear_to_color(al_map_rgb(0,0,0));

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

            while(game_is_game_over(&game));
        }
    }

    game_release(&game);

    return 0;
}
