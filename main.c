/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:58:46 by abita             #+#    #+#             */
/*   Updated: 2025/07/26 21:08:57 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
* You have two separate things:
*   t_data: Handles MLX window, rendering, and images
*   t_fractal: Handles logic for fractals (zoom, iterations, etc.)
*/
int main(int argc, char **argv)
{
    t_data data;
    t_fractal fract;

    fract.data = &data; //link the fractal to window
    init_window_and_display(&data);
    input_validity(&fract, argc, argv);
    mlx_hook(data.win, 2, 1L << 0, keyhandler, &data);
    mlx_hook(data.win, 17, 1L << 2, ft_exit, &data);
    mlx_loop(data.mlx);
    return (0);
}
