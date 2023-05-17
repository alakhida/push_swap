#include "push_swap.h"
#include <unistd.h>

char    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}

int print_error(int i)
{
    if (i == 1)
        ft_putstr("erroooooorrrrrrr\n");
    else if (i == 2)
        ft_putstr("not enough arg\n");
    exit (1);
}
