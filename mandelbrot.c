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

// i do this to compute distance form the origin, like the pythagorean theorem
// when the sum of the squares of teh real and imag parts exceed 4 the 
// point has exceeded 4  
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
static int mandelbrot_iterate(t_fractal *fract)
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
    if (i == fract->max_iter)
        fract->color = BLACK; // black color
    else
        fract->color = ((i + 1) * 255 / fract->max_iter) * BLUE;
    return (i);
}
static void mandelbrot_init_coords(t_fractal *fract, int x, int y)
{
    fract->z.real = 0;
    fract->z.imag = 0;
    fract->c.real= (double)(x - (WIDTH / 2)) / (WIDTH / 4);
    fract->c.real *= fract->zoom;
    fract->c.imag = (double)(y - (HEIGHT / 2)) / (HEIGHT / 4);
    fract->c.imag *= fract->zoom; 
}
int ft_mandelbrot(t_fractal *fract)
{
    int x;
    int y;

    fract->max_iter = 80;
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
