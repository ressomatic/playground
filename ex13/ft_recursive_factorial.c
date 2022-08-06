/*Iterate a fraction through recursion.
Does this fill the condition? No? Retry. What's the condition?
Probably where the amount of "rounds" is [parameter - 1]*/

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

int ft_recursive_factorial(int nb)
{
    if (nb == 0)
    {
        return (1);
    }
    else if(nb < 0 || nb > 12)
    {
        return (0);
    }
    else
        ft_putnbr(nb);
        ft_putchar('\n');
        return (nb * ft_recursive_factorial(nb - 1));
}

int main(void)
{
    ft_putnbr(ft_recursive_factorial(5));
    ft_putchar('\n');
    ft_putnbr(ft_recursive_factorial(0));
    ft_putchar('\n');
    ft_putnbr(ft_recursive_factorial(13));
    ft_putchar('\n');
}