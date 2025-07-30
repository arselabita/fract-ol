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

t_complex complex_square(t_complex z)
{
    t_complex result;
 
    result.real = (z.real * z.real) - (z.imag * z.imag);
    result.imag = 2 * z.real * z.imag;
    return (result);
}
double magnitude(t_complex z)
{
    return (sqrt(z.real * z.real + z.imag * z.imag));
} 
int ft_mandelbrot(t_fractal *fract)
{
    t_complex temp;
    double real;
    double imag;
    int x;
    int y;

    fract->max_iter = 50;
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            real = (double)(x - (WIDTH / 2)) / (double)(WIDTH / 4);
            imag = (double)(y - (HEIGHT / 2)) / (double)(HEIGHT / 4);
            fract->z.real = real;
            fract->c.imag = imag;
            fract->z.real = 0;
            fract->c.imag = 0;
            fract->i = 0;
            while (fract->i < fract->max_iter)
            {
                temp = complex_square(fract->z);
                fract->z.real = temp.real + fract->c.real;
                fract->z.imag = temp.imag + fract->c.imag;
                if (magnitude(fract->z) > 2.0)
                    break;
                fract->i++;
            }
            if (fract->i == fract->max_iter)
                fract->color = 0x00000000;
            else
                fract->color = 0xFFFFFF * fract->i / fract->max_iter; 
            my_pixel_put(fract->data->img, x, y, fract->color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->data->mlx, fract->data->win, fract->data->img.img, 0, 0);
    return (0);
}
