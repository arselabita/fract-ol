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

int	ft_strcmp(char *s1, char *s2)
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

void input_validity(t_data data, int argc, char **argv)
{
    int x;
    int y;

    x = 0;
    y = 0;
    if (argc < 2)
        return (1, write(1, "Error write Mandelbrot or Juliaaaa :)", 44));
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        ft_mandelbrot();
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        if (argc < 4)
        {
            write(1, "Julia, needs two parameters, x and y!\n", 39);
            return (1);
        }
        x = ft_atoi(argv[1]);
        y = ft_atoi(argv[2]);
        ft_julia(x, y);
    }
    else
        return(1, write(1, "Please input the right fractal type: \
			   Mandelbrot or Julia\n", 58));
}
