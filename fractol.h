#ifndef FRACTOL_H
# define FRACTOL_H

# define X_MIN -2.0
# define X_MAX 1.0
# define Y_MIN -1.5
# define Y_MAX 1.5

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

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

#endif