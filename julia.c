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

static int julia_iterate(t_fractal *fract, int a, int b)
{
    t_complex temp;
    int i;

    i = 0;
    while (i < fract->max_iter)
    {
        temp = complex_square(fract->z);
    }
}
static void julia_init_coords(t_fractal *fract, int x, int y)
{
    fract->z.real = 0;
    fract->z.imag = 0;
    fract->c.real = (double)(x - (WIDTH / 2) / (WIDTH / 4));
    fract->c.imag = (double)(y - (HEIGHT / 2) / (HEIGHT / 4));
}
void ft_julia(t_fractal *fract, double param1, double param2)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            julia_init_coords(fract, x, y);
            fract->i = julia_iterate(fract, param1, param2);
            my_pixel_put(fract->data->img, x, y, fract->color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->data->mlx, fract->data->win, \
        fract->data->img.img, 0, 0);
    return (0);
}
