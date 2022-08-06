#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int *ft_range(int min, int max)
{
    int i = 1;
    int size = max - min;
    int *k = (int *)malloc(sizeof(int) * size);

    while(min < max)
    {
        k[i] = min++;
        ft_putnbr(k[i]);
        ft_putchar('\n');
        i++;
    }
    return(k);
}

int main(void)
{
    int a = 1;
    int b = 20;

    ft_range(a, b);
    return (0);
}