/*strcmp + switch pointers but with sysargs*/

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

int main(int argc, char **argv)
{
    int i = 1;
    char *t;

    while(i < argc)
    {
        int j = 1;
        while(j < argc)
        {
            if(ft_strcmp(argv[i], argv[j]) < 0)
            {
                t = argv[i];
                argv[i] = argv[j];
                argv[j] = t;
            }
            j++;
        }
        i++;
    }   

    i = 1;
    while(i < argc)
    {
        ft_putstr(argv[i]);
        ft_putchar('\n');
        i++;
    }
    return (0);
}