#include "../include/cell.h"

int main(int argc, char const *argv[])
{
    struct cell *bacteria = create_cell();

    bacteria->init(bacteria, 0, 0);

    return 0;
}
