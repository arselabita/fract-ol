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
static void fract_type(t_fractal *fract)
{
    if (fract->return_f == MANDELBROT)
        ft_mandelbrot(fract);
    else if (fract->return_f == JULIA)
        ft_julia(fract, fract->p1, fract->p2);
    else if (fract->return_f == MULTIBROT)
        ft_multibrot(fract);
}
static void keyhandler_iter(int key, t_fractal *fract)
{
    if (key == I_KEY)
        fract->max_iter += 10;
    else if (key == D_KEY)
        fract->max_iter -= 10;
}
static void keyhandler_color(int key, t_fractal *fract)
{
    if (key == R_KEY)
        fract->base_color = RED;
    else if (key == P_KEY)
        fract->base_color = PURPLE;
    else if (key == N_KEY)
        fract->base_color = PINK;
}
static int keyhandler(int key, t_data *data)
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
    keyhandler_color(key, fract);
    keyhandler_iter(key, fract);
    fract_type(fract);
    return (0);
}
static int mouse_hook(int button, int x, int y, t_fractal *fract)
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
