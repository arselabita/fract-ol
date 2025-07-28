/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:58:39 by abita             #+#    #+#             */
/*   Updated: 2025/07/26 21:08:54 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void ft_mandelbrot(t_fractal *fract)
{
    // if z goes to infinity
    if (fract->z > pow(10, 8))
    {
        // color the pixel with sp,e color (render code here)
    }
    // if z fails to go to infinity
    else
    {
        // color the pixel black or continue iteration
    }
}
void ft_julia(t_fractal *fract, double param1, double param2)
{
    printf("juldddia");
}

