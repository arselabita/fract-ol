#include "fractol.h"

int main(int ac, char **av)
{
    if (ac == 2)
        ft_fractal(av[1]);
    else
        write(1, "Erorrrrrrrr write Mandelbrot or Juliaaaa :)", 44);
    return (0);
}