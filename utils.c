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

double	magnitude(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imag * z.imag);
	result.imag = 2 * z.real * z.imag;
	return (result);
}

t_complex	complex_square_m(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real * z.real * z.real) - \
		6 * ((z.real * z.real) * (z.imag * z.imag)) + \
			(z.imag * z.imag * z.imag * z.imag);
	result.imag = (4 * ((z.real * z.real * z.real) * (z.imag))) - \
		(4 * ((z.real) * (z.imag * z.imag * z.imag)));
	return (result);
}

void	ft_color_fract(t_fractal *fract, int i)
{
	if (i == fract->max_iter)
		fract->color = BLACK;
	else
		fract->color = ((i + 1) * 255 / fract->max_iter) * BLUE;
}

void	var_init(t_fractal *fract)
{
	fract->max_iter = 80;
	fract->zoom = 1.0;
	fract->move_x = 0.0;
	fract->move_y = 0.0;
}
