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

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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

typedef struct s_fractal
{
    t_data *data; // pointer to rendering info
    double x;
    double y;
    double z;

} t_fractal;

void    input_validity(t_data *data, int argc, char **argv);
void ft_mandelbrot(t_fractal *fract);
void ft_julia(t_fractal *fract, double param1, double param2);

#endif
