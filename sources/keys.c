/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:41 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 22:33:20 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tap_rotation(int key, t_fdf *data)
{
	if (key == 12)
		data->alpha += 0.2;
	if (key == 0)
		data->alpha -= 0.2;
	if (key == 13)
		data->beta += 0.2;
	if (key == 1)
		data->beta -= 0.2;
	if (key == 14)
		data->gamma += 0.2;
	if (key == 2)
		data->gamma -= 0.2;
	if (key == 49)
	{
		data->alpha = 0;
		data->beta = 0;
		data->gamma = 0;
	}
}

void	tap_shift(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 83)
		data->vroom -= 10;
	if (key == 85)
		data->vroom += 10;
}

void	tap_zoom(int key, t_fdf *data)
{
	if (key == 69)
		data->zoom *= 2;
	if (key == 78 && data->zoom >= 2)
		data->zoom /= 2;
	if (key == 89)
		data->brutal = 1;
	if (key == 91)
		data->brutal = 0;
	if (key == 84)
		data->is_iso = 1;
	if (key == 87)
		data->is_iso = 0;
}

void	tap_esc(int key)
{
	if (key == 53)
	{
		exit(0);
	}
}

int		tap(int key, t_fdf *data)
{
	tap_shift(key, data);
	tap_zoom(key, data);
	tap_rotation(key, data);
	tap_esc(key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
