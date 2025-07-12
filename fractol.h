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

typedef struct s_fract
{
    void *mlx;
    void *win;
    t_img img;
    
    int width;
    int height;

    double x_min;
    double x_max;
    double y_min;
    double y_max; 

} t_fract;

void init_window_and_display();
void ft_fractal(int ac, char **av);

#endif