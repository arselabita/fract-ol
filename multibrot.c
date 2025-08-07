/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:55:29 by abita             #+#    #+#             */
/*   Updated: 2025/08/07 17:55:32 by abita            ###   ########.fr       */
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
    
    result.real = (z.real * z.real * z.real * z.real) - \
        6 * ((z.real * z.real) * (z.imag * z.imag)) + \
        (z.imag * z.imag * z.imag * z.imag);
    result.imag = (4 * ((z.real * z.real * z.real) * (z.imag))) - \
        (4 * ((z.real) * (z.imag * z.imag * z.imag)));
    return (result);
}
int multibrot_iterate(t_fractal *fract)
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
        if (magnitude(fract->z) > 2.0)
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
void multibrot_init_coords(t_fractal *fract, int x, int y)
{
    fract->z.real = 0;
    fract->z.imag = 0;
    fract->c.real= ((double)(x - (WIDTH / 2)) / (WIDTH / (SCALE_FACTOR * fract->zoom))) + fract->move_x;
    fract->c.imag = ((double)(y - (HEIGHT / 2)) / (HEIGHT / (SCALE_FACTOR * fract->zoom))) + fract->move_y;
}
int ft_multibrot(t_fractal *fract)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            multibrot_init_coords(fract, x, y);
            fract->i = multibrot_iterate(fract);
            my_pixel_put(fract->data->img, x, y, fract->color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->data->mlx, fract->data->win, \
        fract->data->img.img, 0, 0);
    return (0);
}
