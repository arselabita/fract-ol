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
#include <stdio.h>

void ft_mandelbrot(t_fractal *fract)
{
    fract->a = 0;
    fract->b = 0;
    fract->iteration = 0;
    fract->max_iter = 1000;
    // if z goes to infinity
    while (fract->z > pow(10, 8) && fract->iteration < fract->max_iter)
    {
    }

}
