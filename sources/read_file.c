/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:12:38 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 13:12:42 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fill_matrix(int *z_line, char *line, fdf *data)
{
    char    **nums;
    int     i;

    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        data->z_min = MIN(data->z_min, z_line[i]);
        data->z_max = MAX(data->z_max, z_line[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
}

int     get_height(char *file_name)
{
    char    *line;
    int     fd;
    int     height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while(get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int     get_width(char *file_name)
{
    char    *line;
    int     fd;
    int     width;

    fd = open(file_name, O_RDONLY, 0);
    width = 0;
    get_next_line(fd, &line);
    width = ft_count_words(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    init_fdf(fdf *data)
{
    data->z_max = 0;
    data->z_min = 0;
    data->shift_x = 150;
    data->shift_y = 150;
    data->vroom = 2;
    data->alpha = 0;
    data->beta = 0;
    data->gamma = 0;
}

int    read_file(char *filename, fdf *data)
{
    int     fd;
    char    *line;
    int     i;

    fd = 0;
    if( access( filename, F_OK ) == -1 )
        return (-1);
    data->height = get_height(filename);
    data->width = get_width(filename);
    if (!(data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1))))
        return (-1);
    i = 0;
    init_fdf(data);
    while (i <= data->height)
    {
        if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1))))
            return (-1);
    }
    fd = open(filename, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i], line, data);
        free(line);
        i++;
    }
    close(fd);
    data->z_matrix[i] = NULL;
    return 0;
}
