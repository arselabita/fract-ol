/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:43:19 by abita             #+#    #+#             */
/*   Updated: 2025/07/28 17:43:23 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

static void	param_julia(t_fractal *fract, char **argv)
{
	fract->p1 = ft_atof(argv[2]);
	fract->p2 = ft_atof(argv[3]);
	if (fract->p1 > 2.0 || fract->p1 < -2.0 || \
		fract->p2 > 2.0 || fract->p2 < -2.0)
	{
		write (2, "Julia parameters must be between -2.0 and 2.0!\n", 48);
		exit (EXIT_FAILURE);
	}
}

int	input_validity(t_fractal *fract, int argc, char **argv)
{
	if (argc < 2)
	{
		write (2, "Choose a fractal: Mandelbrot, Julia or Multibrot!\n", 51);
		exit (EXIT_FAILURE);
	}
	if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (ft_mandelbrot(fract), MANDELBROT);
	else if (argc == 2 && ft_strcmp(argv[1], "Multibrot") == 0)
		return (ft_multibrot(fract), MULTIBROT);
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		if (argc != 4)
		{
			write(2, "Julia, needs two parameters, a and b!\n", 39);
			exit(EXIT_FAILURE);
		}
		param_julia(fract, argv);
		return (ft_julia(fract, fract->p1, fract->p2), JULIA);
	}
	else
	{
		write(2, "Please input: Mandelbrot, Julia or Multibrot!\n", 47);
		exit(EXIT_FAILURE);
	}
	return (0);
}
