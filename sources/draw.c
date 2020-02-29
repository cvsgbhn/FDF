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

void    prepare_color(int z, fdf *data)
{
    if (!data->brutal)
        data->color = get_color_barbie(z, data);
    else
        data->color = get_color_brutal(z, data);
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8) + 350;
    *y = (*x + *y) * sin(0.8) - z;
}

void    prerequisits(float *x, float *y, float *x1, float *y1, int z, int z1, fdf *data)
{
    zoom(x, y, x1, y1, data);
    shift(x, y, x1, y1, data);
    if (data->is_iso == 1)
    {
        isometric(x, y, z);
        isometric(x1, y1, z1);
    }
    if (data->alpha != 0)
    {
        rotation_alpha(y, z, data);
        rotation_alpha(y1, z1, data);
    }
    if (data->beta != 0)
    {
        rotation_beta(x, z, data);
        rotation_beta(x1, z1, data);
    }
    if (data->gamma != 0)
    {
        rotation_gamma(x, y, data);
        rotation_gamma(x1, y1, data);
    }
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
    prerequisits(&x, &y, &x1, &y1, z, z1, data);
    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        prepare_color(z, data); 
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
