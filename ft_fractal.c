#include "fractol.h"

ft_mandelbrot()
{
    t_fract z;
    t_fract c;
    double tmp;
    int i;

    i = 0;
    z.re = 0;
    z.im = 0;
    c.re = 5;
    c.im = 2;
    while (i < 100)
    {
        tmp = (z.re * z.re) - (z.im * z.im);
        z.im = 2 * z.re * z.im;
        z.re = tmp;
        z.re += c.re;
        z.im += z.im; 
        i++;
    }

}

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

