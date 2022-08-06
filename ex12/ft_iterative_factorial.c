/*Create an iterated function that returns the factorial of the given number
Factorial of 4 (4!): 4x3x2x1 = 24
Iteration = repetition
In this case, iteration is [parameter] x [parameter - 1] x [parameter - 2] etc until [parameter - n = 1]*/

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

int ft_iterative_factorial(int nb)
{
    int sum = 1;

    if(nb == 0)
    {
        return (1);
    }
    else if(nb < 0 || nb > 12 /*13!+ > int type size*/)
    {
        return (0);
    }
    while(nb >= 1)
    {
        sum = sum * nb;
        ft_putnbr(sum);
        ft_putchar('+');
        ft_putnbr(nb);
        ft_putchar('\n');
        nb--;
    }
    return (sum);
}

int main(void)
{
    int i = 5;
    int k = 0;
    int j = 13;

    ft_putnbr(i);
    ft_putchar('\n');
    ft_putnbr(k);
    ft_putchar('\n');
    ft_putnbr(j);
    ft_putchar('\n');
    ft_putnbr(ft_iterative_factorial(i));
    ft_putchar('\n');
    ft_putnbr(ft_iterative_factorial(k));
    ft_putchar('\n');
    ft_putnbr(ft_iterative_factorial(j));
    ft_putchar('\n');
}