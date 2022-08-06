/*
man strlen
*/

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
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

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i]!= '\0')
    {
        i++;
    }
    return (i);
}

int main(void)
{
    char str_a[] = "hello";
    char str_b[] = "is it me you're looking for";

    ft_putstr(str_a);
    ft_putchar('\n');
    ft_putnbr(ft_strlen(str_a));
    ft_putchar('\n');
    ft_putstr(str_b);
    ft_putchar('\n');
    ft_putnbr(ft_strlen(str_b));
    ft_putchar('\n');
}
