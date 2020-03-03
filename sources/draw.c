/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:28 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 22:32:32 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	prepare_color(int z, t_fdf *data)
{
	if (!data->brutal)
		data->color = get_color_barbie(z, data);
	else
		data->color = get_color_brutal(z, data);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8) + 350;
	*y = (*x + *y) * sin(0.8) - z;
}

void	prerequisits(t_point *xy, t_point *xy1, t_point zz1, t_fdf *data)
{
	zoom(xy, xy1, data);
	shift(xy, xy1, data);
	if (data->alpha != 0)
	{
		rotation_alpha(&xy->y, zz1.x, data);
		rotation_alpha(&xy1->y, zz1.y, data);
	}
	if (data->beta != 0)
	{
		rotation_beta(&xy->x, zz1.x, data);
		rotation_beta(&xy1->x, zz1.y, data);
	}
	if (data->gamma != 0)
	{
		rotation_gamma(&xy->x, &xy->y, data);
		rotation_gamma(&xy1->x, &xy1->y, data);
	}
	if (data->is_iso == 1)
	{
		isometric(&xy->x, &xy->y, zz1.x);
		isometric(&xy1->x, &xy1->y, zz1.y);
	}
}

void	bresenham(t_point *xy, t_point *xy1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		maximum;
	t_point	zz1;

	zz1.x = data->z_matrix[(int)xy->y][(int)xy->x] * data->vroom;
	zz1.y = data->z_matrix[(int)xy1->y][(int)xy1->x] * data->vroom;
	prerequisits(xy, xy1, zz1, data);
	x_step = xy1->x - xy->x;
	y_step = xy1->y - xy->y;
	maximum = fmax(abs((int)x_step), abs((int)y_step));
	x_step /= maximum;
	y_step /= maximum;
	while ((int)(xy->x - xy1->x) || (int)(xy->y - xy1->y))
	{
		prepare_color(zz1.x, data);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, xy->x, xy->y, data->color);
		xy->x += x_step;
		xy->y += y_step;
	}
	free(xy);
	free(xy1);
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(new_point(x, y), new_point(x + 1, y), data);
			if (y < data->height - 1)
				bresenham(new_point(x, y), new_point(x, y + 1), data);
			x++;
		}
		y++;
	}
}
