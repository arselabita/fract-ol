#include "fractol.h"

// to draw one pixel
// y * linelen -> move to the correct row
// x * bpp/8 -> move to the correct column
// add them together -> pointer to a pixel location
// cast the memory and write the color

// writing a raw pixel data into the memory -low-level-drawing
void    my_pixel_put(t_img img, int x, int y, int color)
{
    char* dest;

    dest = img.addr + (y * img.linelen + x * (img.bpp / 8));
    *(unsigned int*)dest = color;
}
// to excit the program
// i free the mlx image, wjndow and display
// free the mlx pointer
// then quit
int ft_exit(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}
// this to handle my keyboard input, so in case ESC is pressed with keycode 6307, 
// means exit my program
int keyhandler(int key, t_data *data)
{
    if (key == 65307)
        ft_exit(data);
    return (0);
}

int main(void)
{
    t_data data; // declaration of the main data struct

    data.mlx = mlx_init(); // initializing MiniLibX
    data.win = mlx_new_window(data.mlx, 1100, 800, "The Fract-ol"); // Create the Window
    data.img.img =  mlx_new_image(data.mlx, 1100, 800); // create a new image of the same size as the window
    // get access to the raw image buffer (addr) and pixel format info
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.linelen, &data.img.endian);

    // this is to just draw a horizontal white line at y = 10 from x = 0 to x = 800
    int i = -1;
    while (++i < 1100)
        my_pixel_put(data.img, i, 10, 0xFFFFFFFF); // color it in white
    // displays the image on the screen (from buffer window)
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
    // listents dor key presses (event = 2 = keypress) -> ESC to quit
    mlx_hook(data.win, 2, 1L << 0, keyhandler, &data);
    // listens for window close (event = 17 destroyNotify) -> X window button to quit
    mlx_hook(data.win, 17, 1L << 2, ft_exit, &data);
    // starts the MLX event loop
    mlx_loop(data.mlx);
}