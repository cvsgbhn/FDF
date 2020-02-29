/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:13:31 by vdanilo           #+#    #+#             */
/*   Updated: 2020/02/29 13:13:33 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNTITLED_FDF_H
#define UNTITLED_FDF_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../minilibx_macos/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a,b) (a <= b ? a : b)
#define MOD(a) (a > 0 ? a : -a)

typedef struct
{
    int     width;
    int     height;
    int     **z_matrix;
    int     zoom;
    int     vroom;
    int     color;
    int     shift_x;
    int     shift_y;
    int    is_iso;
    float  alpha;
    float  beta;
    float  gamma;
    int    z_max;
    int    z_min;
    int    brutal;

    void    *mlx_ptr;
    void    *win_ptr;
}           fdf;

int     read_file(char *filename, fdf *data);
void    bresenham(float x, float y, float x1, float y1, fdf *data);
void    draw(fdf *data);
void    isometric(float *x, float *y, int z);
void     move(int key, fdf *data);
void    shift(float *x, float *y, float *x1, float *y1, fdf *data);
void     tap_shift(int key, fdf *data);
void     tap_zoom(int key, fdf *data);
void    tap_esc(int key);
int     tap(int key, fdf *data);
int     get_color_barbie(int z, fdf *data);
int     get_color_brutal(int z, fdf *data);
void	terminate(char *s);

#endif
