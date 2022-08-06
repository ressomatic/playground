/*print your sysargs*/

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

int main(int argc, char **argv)
{
    int i = 1;
    while(i < argc)
    {
            ft_putstr(argv[i]);
            ft_putchar('\n');
            i++;
    }
    return (0);
}