/*if a square root of a number is a whole number, return it. otherwise return 0.*/

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

int ft_sqrt(int nb)
{
    int i = 1;

    if(nb <= 0)
    {
        return (0);
    }
    while(nb >= i * i)
    {
        if(nb == i * i)
        {
            return (i);
            break;
        }
        i++;
    }
    return (0);

}

int main(void)
{
    ft_putnbr(ft_sqrt(25));
    ft_putchar('\n');
    ft_putnbr(ft_sqrt(7));
    ft_putchar('\n');
    ft_putnbr(ft_sqrt(0));
    ft_putchar('\n');
    ft_putnbr(ft_sqrt(16));
    ft_putchar('\n');
    ft_putnbr(ft_sqrt(25012960));
    ft_putchar('\n');
    ft_putnbr(ft_sqrt(251236));
    ft_putchar('\n');
}