#include "fdf.h"

void    fill_matrix(int *z_line, char *line)
{
    char    **nums;
    int     i;

    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
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

void    read_file(char *filename, fdf *data)
{
    int     fd;
    char    *line;
    int     i;

    fd = 0;
    data->height = get_height(filename);
    data->width = get_width(filename);
    data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
    fd = open(filename, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i], line);
        free(line);
        i++;
    }
    close(fd);
    data->z_matrix[i] = NULL;
    data->shift_x = 150;
    data->shift_y = 150;
    data->vroom = 2;
    data->angle = 1.0;
    data->is_iso = 1;
}