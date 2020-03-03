/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:13:31 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 22:40:30 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNTITLED_FDF_H
# define UNTITLED_FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			vroom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			is_iso;
	float		alpha;
	float		beta;
	float		gamma;
	int			z_max;
	int			z_min;
	int			brutal;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int				read_file(char *filename, t_fdf *data);
void			bresenham(t_point *xy, t_point *xy1, t_fdf *data);
void			draw(t_fdf *data);
void			isometric(float *x, float *y, int z);
void			move(int key, t_fdf *data);
void			tap_shift(int key, t_fdf *data);
void			tap_zoom(int key, t_fdf *data);
void			tap_esc(int key);
int				tap(int key, t_fdf *data);
int				get_color_barbie(int z, t_fdf *data);
int				get_color_brutal(int z, t_fdf *data);
void			terminate(char *s);
int				ft_isnumber(char *str, int base);
void			rotation_alpha(float *y, int z, t_fdf *data);
void			rotation_beta(float *x, int z, t_fdf *data);
void			rotation_gamma(float *x, float *y, t_fdf *data);
t_point			*new_point(float x, float y);
void			zoom(t_point *xy, t_point *xy1, t_fdf *data);
void			shift(t_point *xy, t_point *xy1, t_fdf *data);
void			init_fdf(t_fdf *data);

#endif
