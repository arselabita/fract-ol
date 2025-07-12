#include "fractol.h"

// this to handle my keyboard input, so in case ESC is pressed with keycode 6307, 
// means exit my program
int keyhandler(int key, t_data *data)
{
    if (key == 65307)
        ft_exit(data);
    return (0);
}