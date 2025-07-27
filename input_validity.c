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
static int	ft_atoi(const char *nptr)
{
	long	num;
	int		minus;
	int		i;

	minus = 1;
	num = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return ((int)(num * minus));
}

void input_validity(t_data *data, int argc, char **argv)
{
    if (argc < 2)
        return (1, write (1, "Choose a fractal: 'Mandelbrot' or 'Julia'", 41));
    if (ft_strcmp(argv[1], "Mandelbrot") == 0)
        ft_mandelbrot(&data);
    else if (ft_strcmp(argv[1], "Julia") == 0)
    {
        if (argc < 4)
            return (1, write(1, "Julia, needs two parameters, x and y!\n", 39));
        data.x = ft_atoi(argv[2]);
        data.y = ft_atoi(argv[3]);
        ft_julia(data, x, y);
    }
    else
        return(1, write(1, "Please input the right fractal type: \
			   Mandelbrot or Julia\n", 58));
}
