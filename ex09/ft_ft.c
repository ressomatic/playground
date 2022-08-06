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
    else if(n >= 0 && n <= 10)
    {
        ft_putchar(n + '0');
    }
    else
    {
        /*first character*/
        ft_putnbr(n / 10);
        /*second character(s)*/
        ft_putnbr(n % 10);
    }
}

void ft_ft(int *nbr)
{
    /*pointer value = 42*/
    *nbr = 42;
}

int main(void)
{
    int i = 1337;
    /*assign nbr pointer to i*/
    int *nbr = &i;

    /*show value of i & nbr initially*/
    ft_putnbr(i);
    ft_putchar('\n');
    ft_putnbr(*nbr);
    ft_putchar('\n');
    /*see how i's value changes after ft_ft*/
    ft_ft(nbr);
    ft_putnbr(i);
    ft_putchar('\n');
}