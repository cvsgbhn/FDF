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

#define MAX(a, b) (a > b ? a : b)
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
    float   angle;
    int     is_iso;

    void    *mlx_ptr;
    void    *win_ptr;
}           fdf;

void    read_file(char *filename, fdf *data);
void    bresenham(float x, float y, float x1, float y1, fdf *data);
void    draw(fdf *data);
void    isometric(float *x, float *y, int z);
void     move(int key, fdf *data);
void    shift(float *x, float *y, float *x1, float *y1, fdf *data);
void     tap_shift(int key, fdf *data);
void     tap_zoom(int key, fdf *data);
void    tap_esc(int key);
int     tap(int key, fdf *data);

#endif
