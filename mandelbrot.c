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

int mandelbrot_iterate(t_fractal *fract)
{
    t_complex temp;
    int i;

    i = 0;
    while (i < fract->max_iter)
    {
        temp = complex_square(fract->z);
        fract->z.real = temp.real + fract->c.real;
        fract->z.imag = temp.imag + fract->c.imag;
        if (magnitude(fract->z) > 2.0)
            break;
        i++;
    }
    ft_color_fract(fract, i);
    return (i);
}
void mandelbrot_init_coords(t_fractal *fract, int x, int y)
{
    fract->z.real = 0;
    fract->z.imag = 0;
    fract->c.real= ((double)(x - (WIDTH / 2)) / (WIDTH / (SCALE_FACTOR * fract->zoom))) + fract->move_x;
    fract->c.imag = ((double)(y - (HEIGHT / 2)) / (HEIGHT / (SCALE_FACTOR * fract->zoom))) + fract->move_y;
}
int ft_mandelbrot(t_fractal *fract)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            mandelbrot_init_coords(fract, x, y);
            fract->i = mandelbrot_iterate(fract);
            my_pixel_put(fract->data->img, x, y, fract->color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->data->mlx, fract->data->win, \
        fract->data->img.img, 0, 0);
    return (0);
}
