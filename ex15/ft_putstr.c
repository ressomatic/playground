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

int main(void)
{
    /*LOL YOU CAN'T USE SINGLE QUOTES*/
    char str_a[] = "hello";
    char str_b[] = "is it me you\'re looking for";

    ft_putstr(str_a);
    ft_putchar('\n');
    ft_putstr(str_b);
    ft_putchar('\n');

}