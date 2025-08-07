/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:10:31 by abita             #+#    #+#             */
/*   Updated: 2025/08/07 21:10:33 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button, int x, int y, t_fractal *fract)
{
    (void)x;
    (void)y;

    if (button == SCROLL_UP)
        fract->zoom *= 0.9;
    else if (button == SCROLL_DOWN)
        fract->zoom /= 0.9;
    fract_type(fract);
    return (0);
}
void fract_type(t_fractal *fract)
{
    if (fract->return_f == MANDELBROT)
        ft_mandelbrot(fract);
    else if (fract->return_f == JULIA)
        ft_julia(fract, fract->p1, fract->p2);
    else if (fract->return_f == MULTIBROT)
        ft_multibrot(fract);
}
void keyhandler_iter(int key, t_fractal *fract)
{
    if (key == I_KEY)
        fract->max_iter += 10;
    else if (key == D_KEY)
        fract->max_iter -= 10;
}

int keyhandler(int key, t_data *data)
{
    t_fractal *fract = data->fract;
    double move_speed;
    double step;

    step = 10.0;
    move_speed = step / (WIDTH / (SCALE_FACTOR * fract->zoom));
    if (key == ESC)
        ft_exit(data);
    else if (key == LEFT)
        fract->move_x -= move_speed;
    else if (key == RIGHT)
        fract->move_x += move_speed;
    else if (key == UP)
        fract->move_y -= move_speed;
    else if (key == DOWN)
        fract->move_y += move_speed;
    keyhandler_iter(key, fract);
    fract_type(fract);
    return (0);
}
