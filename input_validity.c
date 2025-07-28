/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:59:28 by abita             #+#    #+#             */
/*   Updated: 2025/07/26 21:09:02 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"	

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
static double	ft_atof(const char *nptr)
{
	double	result;
	double	factor;
	int			sign;
	int		i;

	sign = 1;
	result = 0.0;
	factor = 0.1;
	i = 0.0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10.0 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
	{
		i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result += (nptr[i] - '0') * factor;
			factor *= 0.1;
			i++;
		}
	}
	return (result * sign);
}

void input_validity(t_fractal *fract, int argc, char **argv)
{
    if (argc < 2)
	{
		write (1, "Choose a fractal: 'Mandelbrot' or 'Julia'", 41);
		exit (1);
	}
    if (ft_strcmp(argv[1], "Mandelbrot") == 0)
        ft_mandelbrot(fract);
    else if (ft_strcmp(argv[1], "Julia") == 0)
    {
        if (argc < 4)
		{
			write(1, "Julia, needs two parameters, x and y!\n", 39);
			exit (1);
		}
		double param1 = ft_atof(argv[2]);
		double param2 = ft_atof(argv[3]);
        fract->x = param1;
        fract->y = param2;
        ft_julia(fract, param1, param2);
    }
    else
    {
		write(1, "Please input the right fractal type: Mandelbrot or Julia\n", 58);
		exit(1);
	}
}
