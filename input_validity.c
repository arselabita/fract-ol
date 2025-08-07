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
#include "../Libft/libft.h"

int input_validity(t_fractal *fract, int argc, char **argv)
{
    if (argc < 2)
	{
		write (2, "Choose a fractal: 'Mandelbrot' or 'Julia'!", 42);
		exit (1);
	}
    if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (ft_mandelbrot(fract), MANDELBROT);
    else if (ft_strcmp(argv[1], "Julia") == 0)
    {
        if (argc < 4)
		{
			write(2, "Julia, needs two parameters, a and b!\n", 39);
			exit(1);
		}
		fract->p1 = ft_atof(argv[2]);
        fract->p2 = ft_atof(argv[3]);
		return (ft_julia(fract, fract->p1, fract->p2), JULIA);
    }
	else if (ft_strcmp(argv[1], "Multibrot") == 0)
		return (ft_multibrot(fract), MULTIBROT);
    else
	{
		write(2, "Please input: Mandelbrot, Julia or Multibrot!\n", 47);
 		exit(1);
	}
	return (0);
}
