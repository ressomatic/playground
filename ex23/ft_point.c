#include "ft_point.h"
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if(n < 0)
    {
        n = -n;
        ft_putchar('-');
        ft_putnbr(n);
    }
    else if(n >= 0 && n < 10)
    {
        ft_putchar(n + 48);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

void    set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
}

int main(void)
{
    t_point point;

    set_point(&point);
    ft_putnbr(point.x);
    ft_putchar('\n');
    ft_putnbr(point.y);
    ft_putchar('\n');
    return(0);
}