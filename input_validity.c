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
static void parse_integer_part(const char *nptr, t_atof *a)
{
	while ((nptr[a->i] >= '\t' && nptr[a->i] <= '\r') || nptr[a->i] == ' ')
		a->i++;
	if (nptr[a->i] == '-' || nptr[a->i] == '+')
	{
		if (nptr[a->i] == '-')
			a->sign = -1;
		a->i++;
	}
	while (nptr[a->i] >= '0' && nptr[a->i] <= '9')
	{
		a->result = a->result * 10.0 + (nptr[a->i] - '0');
		a->i++;
	}
}
static double	ft_atof(const char *nptr)
{
	t_atof a;

	a.sign = 1;
	a.result = 0.0;
	a.factor = 0.1;
	a.i = 0.0;
	parse_integer_part(nptr, &a);
	if (nptr[a.i] == '.')
	{
		a.i++;
		while (nptr[a.i] >= '0' && nptr[a.i] <= '9')
		{
			a.result += (nptr[a.i] - '0') * a.factor;
			a.factor *= 0.1;
			a.i++;
		}
	}
	return (a.result * a.sign);
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
			write(1, "Julia, needs two parameters, a and b!\n", 39);
			exit (1);
		}
        fract->a = ft_atof(argv[2]);
        fract->b = ft_atof(argv[3]);
        ft_julia(fract, fract->a, fract->b);
    }
    else
    {
		write(1, "Please input the right fractal type: Mandelbrot or Julia\n", 58);
		exit(1);
	}
}
