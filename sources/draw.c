/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:28 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 13:11:31 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        if (!data->brutal)
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
