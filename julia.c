/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:43:29 by abita             #+#    #+#             */
/*   Updated: 2025/07/28 17:43:34 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double magnitude(t_complex z)
{
    return (sqrt(z.real * z.real + z.imag * z.imag));
}
static t_complex complex_square(t_complex z)
{
    t_complex result;

    result.real = (z.real * z.real) - (z.imag * z.imag);
    result.imag = 2 * z.real * z.imag;
    return (result);
}
int julia_iterate(t_fractal *fract)
{
    t_complex temp;
    t_color renk;
    int i;

    i = 0;
    while (i < fract->max_iter)
    {
        temp = complex_square(fract->z);
        fract->z.real = temp.real + fract->c.real;
        fract->z.imag = temp.imag + fract->c.imag;
        if(magnitude(fract->z) > 2.0)
            break;
        i++;
    }
    if (i == fract->max_iter)
        fract->color = BLACK;
    else
    {
        fract->intensity = ((i + 1) * 255 / fract->max_iter) * fract->base_color;
        color_range(fract, renk);
        fract->color = (renk.r << 16) | (renk.g >> 8) | renk.b;
    }
    return (i);
}
void julia_init_coords(t_fractal *fract, int x, int y)
{
    fract->z.real= ((double)(x - (WIDTH / 2)) / (WIDTH / (SCALE_FACTOR * fract->zoom))) + fract->move_x;
    fract->z.imag = ((double)(y - (HEIGHT / 2)) / (HEIGHT / (SCALE_FACTOR * fract->zoom))) + fract->move_y;
}
int ft_julia(t_fractal *fract, double param1, double param2)
{
    int x;
    int y;

    fract->c.real = param1;
    fract->c.imag = param2;
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            julia_init_coords(fract, x, y);
            fract->i = julia_iterate(fract);
            my_pixel_put(fract->data->img, x, y, fract->color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->data->mlx, fract->data->win, \
        fract->data->img.img, 0, 0);
    return (0);
}
