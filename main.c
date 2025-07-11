#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_img
{
    void* img;
    char* addr;
    int linelen;
    int bpp;
    int endian;
}   t_img;

typedef struct s_data
{
    void *mlx;
    void *win;
    t_img img;
}   t_data;

void    my_pixel_put(t_img img, int x, int y, int color)
{
    char* dest;

    dest = img.addr + (y * img.linelen + x * (img.bpp / 8));
    *(unsigned int*)dest = color;
}

int ft_exit(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}

int keyhandler(int key, t_data *data)
{
    if (key == 65307)
        ft_exit(data);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 400, 400, "abitas fractol");
    data.img.img =  mlx_new_image(data.mlx, 400, 400);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.linelen, &data.img.endian);
    int i = -1;
    while (++i < 400)
        my_pixel_put(data.img, i, 10, 0xFFFFFFFF);
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
    mlx_hook(data.win, 2, 1L << 0, keyhandler, &data);
    mlx_hook(data.win, 17, 1L << 2, ft_exit, &data);
    mlx_loop(data.mlx);
}