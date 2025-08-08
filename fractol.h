/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:56:35 by abita             #+#    #+#             */
/*   Updated: 2025/08/08 12:06:46 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// scaling
# define WIDTH 800
# define HEIGHT 800
# define SCALE_FACTOR 5

// signals
# define MANDELBROT 1
# define JULIA 3 
# define MULTIBROT 4

// escape key
# define ESC 65307

// arrow keys
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

// mouse scroll
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// letter keys
# define I_KEY 0x0069
# define D_KEY 0x0064

// colors
# define BLACK 0x00000000
# define BLUE 0x00025F

// libraries
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "../Libft/libft.h"

typedef struct s_data		t_data;
typedef struct s_fractal	t_fractal;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		linelen;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_fractal	*fract;
	t_img		img;
	void		*mlx;
	void		*win;
	int			i;

}	t_data;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractal
{
	t_data		*data;
	t_complex	c;
	t_complex	z;
	double		p1;
	double		p2;
	double		denom;
	int			i;
	int			max_iter;
	int			color;
	int			return_f;
	double		move_x;
	double		move_y;
	double		zoom;
	int			base_color;
}	t_fractal;

// parsing
int			input_validity(t_fractal *fract, int argc, char **argv);
void		var_init(t_fractal *fract);

// the fractals
int			ft_mandelbrot(t_fractal *fract);
int			ft_julia(t_fractal *fract, double param1, double param2);
int			ft_multibrot(t_fractal *fract);

// init window and mlx funct
void		init_window_and_display(t_data *data);
void		my_pixel_put(t_img img, int x, int y, int color);
void		mlx_loop_helper(t_data *data, t_fractal *fract);
int			keyhandler(int key, t_data *data);
void		keyhandler_iter(int key, t_fractal *fract);
void		fract_type(t_fractal *fract);
int			mouse_hook(int button, int x, int y, t_fractal *fract);
int			ft_exit(t_data *data);

// coloring funct
void		ft_color_fract(t_fractal *fract, int i);

// math funct
t_complex	complex_square(t_complex z);
t_complex	complex_square_m(t_complex z);
double		magnitude(t_complex z);

#endif
