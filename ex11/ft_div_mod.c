/*
Create a function called div_mod.
This function takes two integers, a and b, and divides a / b.
a / b -> result is stored into pointer *div.
a % b -> result is stored into pointer *mod.
*/

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
        ft_putchar(n + '0');
    }
    else
    {
        /*is this recursion*/
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }

}

void ft_div_mod(int a, int b, int *div, int *mod)
{
    if(b != 0)
    {
        *div = a / b;
        *mod = a % b;
    }
}

int main(void)
{
    int a = 11;
    int b = 5;

    int d = 0;
    int m = 0;

    int *div = &d;
    int *mod = &m;

    ft_putnbr(a);
    ft_putchar('\n');
    ft_putnbr(b);
    ft_putchar('\n');
    ft_div_mod(a, b, div, mod);
    ft_putnbr(d);
    ft_putchar('\n');
    ft_putnbr(m);
    ft_putchar('\n');
}