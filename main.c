/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:58:46 by abita             #+#    #+#             */
/*   Updated: 2025/07/26 21:08:57 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_data data;

    input_validity(&data, argc, argv);
    init_window_and_display(&data);
    return (0);
}
