/*man strcmp*/

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

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    int flag = 0;

    if(ft_strlen(s1) < ft_strlen(s2))
    {
        flag = -1;
    }
    else if(ft_strlen(s2) < ft_strlen(s1))
    {
        flag = 1;
    }

    if(s1[i] == s2[i])
    {
        i++;
    }
    else if(s1[i] < s2[i])
    {
        flag = -1;
    }
    else if(s2[i] < s1[i])
    {
        flag = 1;
    }
    return (flag);
}

int main(void)
{
    ft_putnbr(ft_strcmp("abc", "ab"));
    ft_putchar('\n');
    ft_putnbr(ft_strcmp("bc", "ab"));
    ft_putchar('\n');
    ft_putnbr(ft_strcmp("ab", "bc"));
    ft_putchar('\n');
    ft_putnbr(ft_strcmp("abc", "abc"));
    ft_putchar('\n');
    ft_putnbr(ft_strcmp("cba", ""));
    ft_putchar('\n');
    ft_putnbr(ft_strcmp("", "ab"));
    ft_putchar('\n');
}