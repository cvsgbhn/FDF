/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:12:38 by vdanilo           #+#    #+#             */
/*   Updated: 2020/03/05 15:24:22 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(int *z_line, char *line, t_fdf *data)
{
	char	**nums;
	int		i;

	if ((ft_count_words(line, ' ')) != data->width)
		terminate("Reading error");
	ft_count_words(line, ' ');
	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		if (!ft_isdigit(nums[i][0]) && nums[i][0] != '-')
			terminate("Reading error");
		z_line[i] = ft_atoi(nums[i]);
		data->z_min = fmin(data->z_min, z_line[i]);
		data->z_max = fmax(data->z_max, z_line[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int		*get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		*hw;

	fd = open(file_name, O_RDONLY, 0);
	hw = (int *)malloc(sizeof(int) * 2);
	hw[0] = 0;
	while (get_next_line(fd, &line))
	{
		if (hw[0] == 0)
			hw[1] = ft_count_words(line, ' ');
		hw[0]++;
		ft_memdel((void **)&line);
	}
	free(line);
	close(fd);
	return (hw);
}

void	init_fdf(t_fdf *data)
{
	data->z_max = 0;
	data->z_min = 0;
	data->shift_x = 150;
	data->shift_y = 150;
	data->vroom = 2;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->z_matrix = NULL;
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
	int		*hw;

	if ((fd = open(filename, O_RDONLY, 0)) < 0)
		return (-1);
	close(fd);
	init_fdf(data);
	hw = get_height(filename);
	data->height = hw[0];
	data->width = hw[1];
	ft_memdel((void**)&hw);
	if ((allocate_matrix(data)) == -1)
		return (-1);
	fd = open(filename, O_RDONLY, 0);
	i = -1;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[++i], line, data);
		ft_memdel((void **)&line);
	}
	close(fd);
	return (0);
}
