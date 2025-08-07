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

void    my_pixel_put(t_img img, int x, int y, int color)
{
    char* dest;

    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || !img.addr)
        return;
    dest = img.addr + (y * img.linelen + x * (img.bpp / 8));
    *(unsigned int*)dest = color;
}
void mlx_loop_helper(t_data *data, t_fractal *fract)
{
    mlx_mouse_hook(data->win, mouse_hook, fract);
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
