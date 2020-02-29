#include "../includes/fdf.h"

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