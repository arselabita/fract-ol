/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:43:44 by abita             #+#    #+#             */
/*   Updated: 2025/07/28 17:43:46 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void complex(t_complex z)
{
    t_complex result;
 
    result.real = (z.real * z.real) - (z.imag * z.imag);
    result.imag = 2 * z.real * z.imag;
}
double magnitude(t_fractal *fract)
{
    return (sqrt((z * fract->z) + (fract->c * fract->c)));
} 
int ft_mandelbrot(t_fractal *fract)
{
    fract->z.real = 0;
    fract->c.imag = 0;
    fract->i = 0;
    fract->max_iter = 50;
    while (fract->i < fract->max_iter)
    {
        fract->z = complex(fract->z * fract->z) + fract->c;
        my_pixel_put(fract->data->img, fract->data->i, 10, 0xFFFFFFFF);
        if (abs(fract->z) > 2)
            break;
        fract->i++;
    }
    return (fract->i);
}

void render()
{
    int i;
    int j;

    i = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < HEIGHT)
        {
            double a = (double)(i - (WIDTH / 2)) / (double)(WIDTH / 4);
            double b = (double)(i - (HEIGHT / 2)) / (double)(HEIGHT / 4);
            j++;
        }
        i++;
    }
}
