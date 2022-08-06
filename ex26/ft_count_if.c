#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    ft_putchar(n + 48);
}

/*idea from github*/
int ft_test(char *str)
{
    if(str[0] == 'a')
    {
        return (1);
    }
    else
    {
        return(0);
    }
}

int ft_count_if(char **tab, int(*f)(char*))
{
    int i = 0;
    int k = 0;

    while(tab[i] != 0);
    {
        if(f(tab[i]) == 1)
        {
            k++;
            i++;
        }
    i++;
    }
    return (k);
}

int main(void)
{
    /*copied from github*/
    char **s;
    s = (char**)malloc(sizeof(char*)*3);
    s[0] = "abc";
    s[1] = "bcd";
    s[2] = "efg";


    ft_putnbr(ft_count_if(s, &ft_test));
    return (0);
}