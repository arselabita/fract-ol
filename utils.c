/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:57:48 by abita             #+#    #+#             */
/*   Updated: 2025/08/07 20:57:52 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double magnitude(t_complex z)
{
    return (sqrt(z.real * z.real + z.imag * z.imag));
}
t_complex complex_square(t_complex z)
{
    t_complex result;
 
    result.real = (z.real * z.real) - (z.imag * z.imag);
    result.imag = 2 * z.real * z.imag;
    return (result);
}
t_complex complex_square(t_complex z)
{
    t_complex result;
    
    result.real = (z.real * z.real * z.real * z.real) - \
        6 * ((z.real * z.real) * (z.imag * z.imag)) + \
        (z.imag * z.imag * z.imag * z.imag);
    result.imag = (4 * ((z.real * z.real * z.real) * (z.imag))) - \
        (4 * ((z.real) * (z.imag * z.imag * z.imag)));
    return (result);
}
void color_range(t_fractal *fract, t_color renk)
{
    if (fract->base_color & 0xFF0000)
        renk.r = fract->intensity;
    else if (fract->base_color & 0x00FF00)
        renk.g = fract->intensity;
    else if (fract->base_color & 0x0000FF)
        renk.b = fract->intensity;        
}
void ft_color_fract(t_fractal *fract, int i)
{
    t_color renk;

    renk.r = 0;
    renk.g = 0;
    renk.b = 0;
    if (i == fract->max_iter)
        fract->color = BLACK;
    else
    {
        fract->intensity = ((i + 1) * 255 / fract->max_iter) * fract->base_color;
        color_range(fract, renk);
        fract->color = (renk.r << 16) | (renk.g >> 8) | renk.b;
    }
}