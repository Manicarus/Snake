#include "../include/staff.h"

int main(int argc, char const *argv[]) {

    struct Staff staff;

    stf_init_all(&staff);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_rest(10.0);

    stf_destroy_all(&staff);

    return 0;
}
