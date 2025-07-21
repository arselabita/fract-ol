#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_img
{
    void* img;
    char* addr;
    int linelen;
    int bpp;
    int endian;
}   t_img;

typedef struct s_data
{
    void *mlx;
    void *win;
    t_img img;
}   t_data;

void init_window_and_display();
void ft_fractal(char *av);

#endif