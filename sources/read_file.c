/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:12:38 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 22:35:34 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(int *z_line, char *line, t_fdf *data)
{
	char	**nums;
	int		i;

	if ((ft_count_words(line, ' ')) != data->width)
		terminate("Reading error");
	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		if (ft_isnumber(nums[i], 10) == 0)
			terminate("Reading error");
		z_line[i] = ft_atoi(nums[i]);
		data->z_min = fmin(data->z_min, z_line[i]);
		data->z_max = fmax(data->z_max, z_line[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	width = 0;
	get_next_line(fd, &line);
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int		allocate_matrix(t_fdf *d)
{
	int		i;

	i = 0;
	if (!(d->z_matrix = (int **)malloc(sizeof(int*) * (d->height + 1))))
		return (-1);
	i = 0;
	while (i < d->height)
	{
		if (!(d->z_matrix[i++] = (int*)malloc(sizeof(int) * (d->width + 1))))
			return (-1);
	}
	return (0);
}

int		read_file(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(filename, O_RDONLY, 0)) < 0)
		return (-1);
	close(fd);
	init_fdf(data);
	data->height = get_height(filename);
	data->width = get_width(filename);
	if ((allocate_matrix(data)) == -1)
		return (-1);
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i++], line, data);
		ft_memdel((void **)&line);
	}
	close(fd);
	return (0);
}
