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

# define WIDTH 800
# define HEIGHT 800

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define BLACK 0x00000000
# define BLUE 0x00025F
# define RED 0xFF0000

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
}   t_data;

typedef struct s_atof
{
    double	result;
	double	factor;
	int		sign;
	int		i;
} t_atof;

typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

typedef struct s_fractal
{
    t_data *data; // pointer to rendering info
    t_complex c; // complex num c point in fractal plane
    t_complex z; // complex num z iteration var
    double p1; // param 1
    double p2; // param 2
    int i; // index
    int max_iter;
    int color;
    int return_f;
    double zoom;
} t_fractal;

int    input_validity(t_fractal *fract, int argc, char **argv);
int     ft_mandelbrot(t_fractal *fract);
int     ft_julia(t_fractal *fract, double param1, double param2);
void    init_window_and_display(t_data *data);
void    my_pixel_put(t_img img, int x, int y, int color);


void    mlx_loop_helper(t_data *data, t_fractal *fract);

int     color_func(int key, t_fractal *fract);

int     render_fract(t_fractal *fract, char **argv);

int	    ft_strcmp(char *s1, char *s2);
double	ft_atof(const char *nptr);

void julia_init_coords(t_fractal *fract, int x, int y);
int julia_iterate(t_fractal *fract);







#endif
