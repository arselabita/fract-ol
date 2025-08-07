/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:56:35 by abita             #+#    #+#             */
/*   Updated: 2025/07/26 21:08:50 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// scaling
# define WIDTH 800
# define HEIGHT 800
# define SCALE_FACTOR 5

// signals
# define MANDELBROT 1
# define JULIA 3 
# define MULTIBROT 4

// escape key
# define ESC 65307

// arrow keys
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

// mouse scroll
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// letter keys
# define I_KEY 0x0069
# define D_KEY 0x0064
# define R_KEY 0x52
# define P_KEY 0x50
# define N_KEY 0x4E

// colors
# define BLACK 0x00000000
# define BLUE 0x00025F
# define PURPLE 0XAF69EE
# define PINK 0xFDE6FA1
# define RED 0xC21807

// libraries
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "../Libft/libft.h"

typedef struct s_data t_data;
typedef struct s_fractal t_fractal;

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
    int i;
    t_fractal *fract;
}   t_data;

typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

typedef struct s_fractal
{
    t_data *data;
    t_complex c;
    t_complex z;
    double p1;
    double p2;
    double denom;
    int i;
    int max_iter;
    int color;
    int return_f;
    double move_x;
    double move_y;
    double zoom;
    int base_color;
    int intensity;
} t_fractal;

typedef struct s_color
{
    int r;
    int g;
    int b;
} t_color;

// parsing
int    input_validity(t_fractal *fract, int argc, char **argv);

// the fractals
int     ft_mandelbrot(t_fractal *fract);
int     ft_julia(t_fractal *fract, double param1, double param2);
int     ft_multibrot(t_fractal *fract);

// init window and mlx funct
void    init_window_and_display(t_data *data);
void    my_pixel_put(t_img img, int x, int y, int color);
void    mlx_loop_helper(t_data *data, t_fractal *fract);

// coloring funct
void ft_color_fract(t_fractal *fract, t_color renk, int i);
void color_range(t_fractal *fract, t_color renk);

// math funct
t_complex complex_square(t_complex z);
double magnitude(t_complex z);

#endif
