#include "../includes/fdf.h"

void    tap_iso(int key, fdf *data)
{
    if (key == 87)
        data->is_iso *= -1
}

void    tap_angle(int key, fdf *data)
{
    if (key == 86)
        data->angle += 0.2;
    if (key == 88)
        data->angle -= 0.2;
}

void    tap_vroom(int key, fdf *data)
{
    if (key == 83)
        data->vroom -= 10;
    if (key == 85)
        data->vroom += 10;
}

void    tap_shift(int key, fdf *data)
{
    if (key == 126)
        data->shift_y -= 10;
    if (key == 125)
        data->shift_y += 10;
    if (key == 123)
        data->shift_x -= 10;
    if (key == 124)
        data->shift_x += 10;
}

void     tap_zoom(int key, fdf *data) {
    if (key == 69)
        data->zoom *= 2;
    if (key == 78)
        data->zoom /= 2;
}

void    tap_esc(int key)
{
    if (key == 53)
    {
        exit(0);
    }
}

int     tap(int key, fdf *data)
{
    tap_shift(key, data);
    tap_zoom(key, data);
    tap_vroom(key, data);
    tap_angle(key, data);
    tap_esc(key);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    printf("%d\n", key);
    return (0);
}

