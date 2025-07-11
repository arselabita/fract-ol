#ifndef FRACTOL_H
# define FRACTOL_H
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

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

#endif