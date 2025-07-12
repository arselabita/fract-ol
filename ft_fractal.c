#include "fractol.h"

void ft_fractal(int ac, char **av)
{
    if (av[1] == "mandelbrot")
        ft_mandelbrot();
    else if (av[2] == "julia")
    {
        if (ac == 4)
        {

        }
        else
        {
            write(1, "you forgot smth!", 17);
            exit(0);
        }
    }






    init_window_and_display();
}

