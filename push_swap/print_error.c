#include "push_swap.h"
#include <unistd.h>

void    ft_putstr_2(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        write(2, &str[i], 1);
        i++;
    }
}

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}
int print_error(int i)
{
    if (i == 1)
        ft_putstr_2("\033[0;30mError\n");
    exit (1);
}
