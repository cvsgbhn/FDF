#include "../includes/fdf.h"

int main(int argc, char **argv)
{
    fdf *data;

    if(argc ==2)
    {
        data = (fdf *) malloc(sizeof(fdf));
        read_file(argv[1], data);

        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
        data->zoom = 20;
        draw(data);
        mlx_key_hook(data->win_ptr, tap, data);
        mlx_loop(data->mlx_ptr);
    }
    system("leaks checker");
    return 0;
}
