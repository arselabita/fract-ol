#include "fractol.h"

int main(int argc, char **argv)
{
    t_data data;

    input_validity(&data, argc, argv);
    init_window_and_display(&data);
    return (0);
}
