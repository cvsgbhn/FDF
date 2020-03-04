/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:13 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 22:31:37 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if(placement < 0)
		placement *= -1;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_color_brutal(int z, t_fdf *data)
{
	double	percentage;

	percentage = percent(data->z_min + data->vroom, data->z_max + data->vroom, z + data->vroom);
	if (percentage < 0.25)
		return (0x4C9900);
	if (percentage < 0.5)
		return (0x663300);
	if (percentage < 0.75)
		return (0xA0A0A0);
	else
		return (0x004C99);
}

int		get_color_barbie(int z, t_fdf *data)
{
	double	percentage;

	percentage = percent(data->z_min + data->vroom, data->z_max + data->vroom, z + data->vroom);
	if (percentage < 0.25)
		return (0x66FFB2);
	if (percentage < 0.5)
		return (0x3399FF);
	if (percentage < 0.75)
		return (0x9933FF);
	else
		return (0xFF99CC);
}
