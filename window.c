/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:59:25 by abita             #+#    #+#             */
/*   Updated: 2025/07/26 21:09:29 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int ft_exit(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
static int keyhandler(int key, t_data *data)
{
    if (key == ESC)
        ft_exit(data);
    return (0);
}
void    my_pixel_put(t_img img, int x, int y, int color)
{
    char* dest;
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || !img.addr)
        return;
    dest = img.addr + (y * img.linelen + x * (img.bpp / 8));
    *(unsigned int*)dest = color;
}

int mouse_hook(int button, int x, int y, t_fractal *fract)
{
    (void)x;
    (void)y;

    if (button == 4)
        fract->zoom *= 0.9;
    else if (button == 5)
        fract->zoom /= 0.9;
    if (fract->return_f == 1)
        ft_mandelbrot(fract);
    else if (fract->return_f == 2)
        ft_julia(fract, fract->p1, fract->p2);
    return (0);
}

/* int color_func(int key, t_fractal *fract)
{
    if (key == 0x0072)
        fract->color2 = RED;
    ft_mandelbrot(fract);
    return (0);
} */

int key_hook(int key, t_fractal *fract)
{
    if (key == LEFT)
        fract->zoom *= 1;
    else if (key == RIGHT)
        fract->zoom *= 1;
    else if (key == UP)
        fract->zoom *= 1;
    else if (key == DOWN)
        fract->zoom *= 1;
    return (0);
}

void mlx_loop_helper(t_data *data, t_fractal *fract)
{
    mlx_mouse_hook(data->win, mouse_hook, fract);
    mlx_key_hook(data->win, key_hook, fract);
    mlx_hook(data->win, 2, 1L << 0, keyhandler, data);
    mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
    mlx_loop(data->mlx);
}
void init_window_and_display(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        exit (1);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "The Fract-ol");
    if (!data->win)
        exit (1);
    data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img.img)
        exit (1);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
									  &data->img.linelen, &data->img.endian);
    if (!data->img.addr)
        exit (1);
}
