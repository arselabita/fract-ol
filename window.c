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
    return (0);
}
static void    my_pixel_put(t_img img, int x, int y, int color)
{
    char* dest;

    dest = img.addr + (y * img.linelen + x * (img.bpp / 8));
    *(unsigned int*)dest = color;
}
static int keyhandler(int key, t_data *data)
{
    if (key == 65307)
        ft_exit(data);
    return (0);
}

void init_window_and_display(t_data data)
{
    data.mlx = mlx_init(); 
    data.win = mlx_new_window(data.mlx, 1100, 800, "The Fract-ol"); 
    data.img.img =  mlx_new_image(data.mlx, 1100, 800); 
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, \
									  &data.img.linelen, &data.img.endian);
    data.i = -1;
    while (++data.i < 1100)
        my_pixel_put(data.img, data.i, 10, 0xFFFFFFFF);
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
    mlx_hook(data.win, 2, 1L << 0, keyhandler, &data);
    mlx_hook(data.win, 17, 1L << 2, ft_exit, &data);
    mlx_loop(data.mlx);
}
