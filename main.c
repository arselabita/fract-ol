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
int main(int argc, char **argv)
{       
    int x;
    int y;

    x = ft_atoi(argv[2]);
    y = ft_atoi(argv[3]);

    if (argc < 2)
    {
        write(1, "Erorrrrrrrr write Mandelbrot or Juliaaaa :)", 44);
        return (1);
    }
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        ft_mandelbrot();
    else if (ft_strcmp(argv[1], "julia") == 0)
        ft_julia(x, y);
    else
        printf("Did u put smth wrong?");
        
    //init_window_and_display();
    return (0);
    
}