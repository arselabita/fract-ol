#include "fractol.h"

void ft_fractal(char *av)
{
    init_window_and_display();
    int i;

    i = 0;
    if (av[i] == "mandelbrot")
        ft_mandelbrot();
}

