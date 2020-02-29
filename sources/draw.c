#include "../includes/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int     get_color_brutal(int z, fdf *data)
{
    double  percentage;

    percentage = percent(data->z_min, data->z_max, z);
    if (percentage < 0.25)
        return (0x4C9900);
    if (percentage < 0.5)
        return (0x663300);
    if (percentage < 0.75)
        return (0xA0A0A0);
    else
        return (0x004C99);
}


int     get_color_barbie(int z, fdf *data)
{
    double  percentage;

    percentage = percent(data->z_min, data->z_max, z);
    if (percentage < 0.25)
        return (0x66FFB2);
    if (percentage < 0.5)
        return (0x3399FF);
    if (percentage < 0.75)
        return (0x9933FF);
    else
        return (0xFF99CC);
}

void    rotation_alpha(float *y, int z, fdf *data)
{
    *y = *y * cos(data->alpha) + z * sin(data->alpha);
    z = -(*y) * sin(data->alpha) + z * cos(data->alpha);
}

void    rotation_beta(float *x, int z, fdf *data)
{
    *x = *x * cos(data->beta) + z * sin(data->beta);
    z = z * sin(data->beta) + z * cos(data->beta);
}

void    rotation_gamma(float *x, float *y, fdf *data)
{
    *x = *x * cos(data->gamma) - *y * sin(data->gamma);
    *y = *x * sin(data->gamma) + *y * cos(data->gamma);
}

void    zoom(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x *= data->zoom;
    *y *= data->zoom;
    *x1 *= data->zoom;
    *y1 *= data->zoom;
}

void    shift(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x += data->shift_x;
    *y += data->shift_y;
    *x1 += data->shift_x;
    *y1 += data->shift_y;
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8) + 350;
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;

    z = data->z_matrix[(int)y][(int)x] * data->vroom;
    z1 = data->z_matrix[(int)y1][(int)x1] * data->vroom;
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    zoom(&x, &y, &x1, &y1, data);
    shift(&x, &y, &x1, &y1, data);
    if (data->is_iso == 1)
    {
        isometric(&x, &y, z);
        isometric(&x1, &y1, z1);
    }
    if (data->alpha != 0)
    {
        rotation_alpha(&y, z, data);
        rotation_alpha(&y1, z1, data);
    }
    if (data->beta != 0)
    {
        rotation_beta(&x, z, data);
        rotation_beta(&x1, z1, data);
    }
    if (data->gamma != 0)
    {
        rotation_gamma(&x, &y, data);
        rotation_gamma(&x1, &y1, data);
    }
    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        if (data->brutal == 0)
            data->color = get_color_barbie(z, data);
        else
            data->color = get_color_brutal(z, data);
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}

void    draw(fdf *data)
{
    int     x;
    int     y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}
