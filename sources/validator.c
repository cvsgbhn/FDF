#include "../includes/fdf.h"

int     ft_isnumber(char *n)
{
    int i;

    i = 0;
    if (n[i] == '-')
        i++;
    while(n[i])
    {
        if(!ft_isdigit(n[i]))
            return (-1);
        i++;
    }
    return (0);
}