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