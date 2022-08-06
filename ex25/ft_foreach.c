/*pass functions to all elements of an array*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

long ft_putnbr(long n)
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


long ft_sqrt(long nb)
{
    long i = 1;
    
    if(nb <= 0)
    {
       ft_putnbr(nb);
    }
    while(nb >= i * i)
    {
        if(nb == i * i)
        {
            ft_putchar('1');
            ft_putchar('\n');
            break;
        }
        i++;
    }
}

void ft_foreach(long *tab, long length, long(*f)(long))
{
    long i = 0;

    while(i < length)
    {
        f(tab[i]);
        i++;
    }
}

long main(void)
{
    long tab[1000000];
    ft_foreach(tab, 1000000, &ft_sqrt);
    return (0);
}


