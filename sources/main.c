/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:48 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 13:11:51 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void    free_2darr_int(int **data)
{
    int     i;

    i = 0;
    while (data[i])
    {
        free(data[i]);
        i++;
    } 
    free(data);
}

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int main(int argc, char **argv)
{
    fdf *data;

    if(argc ==2)
    {
        data = (fdf *) malloc(sizeof(fdf));
        if (read_file(argv[1], data) == -1)
            terminate("Reading error");
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
        data->zoom = 20;
        draw(data);
        mlx_key_hook(data->win_ptr, tap, data);
        mlx_loop(data->mlx_ptr);
        free_2darr_int(data->z_matrix); 
        //free(data);
    }
    terminate("Usage: ./fdf MAP_FILE");
    system("leaks checker");
    return 0;
}
