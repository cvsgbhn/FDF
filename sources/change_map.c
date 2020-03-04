/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:40:25 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 22:31:14 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation_alpha(float *y, int z, t_fdf *data)
{
	*y = *y * cos(data->alpha) + z * sin(data->alpha);
	z = -(*y) * sin(data->alpha) + z * cos(data->alpha);
}

void	rotation_beta(float *x, int z, t_fdf *data)
{
	*x = *x * cos(data->beta) + z * sin(data->beta);
	z = -*x * sin(data->beta) + z * cos(data->beta);
}

void	rotation_gamma(float *x, float *y, t_fdf *data)
{
	*x = *x * cos(data->gamma) - *y * sin(data->gamma);
	*y = *x * sin(data->gamma) + *y * cos(data->gamma);
}

void	zoom(t_point *xy, t_point *xy1, t_fdf *data)
{
	xy->x *= data->zoom;
	xy->y *= data->zoom;
	xy1->x *= data->zoom;
	xy1->y *= data->zoom;
}

void	shift(t_point *xy, t_point *xy1, t_fdf *data)
{
	xy->x += data->shift_x;
	xy->y += data->shift_y;
	xy1->x += data->shift_x;
	xy1->y += data->shift_y;
}
