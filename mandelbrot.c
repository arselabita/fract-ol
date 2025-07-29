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
    fract->c = 0;
    fract->z = 0;
    fract->i = 0;
    fract->max_iter = 1000;
    while (fract->i < fract->max_iter)
    {
        fract->z = pow(fract->z, 2) + fract->c;
        if (abs(fract->z) > 2)
            break;
        fract->i++;
    }
}
