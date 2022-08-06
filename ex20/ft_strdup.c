/*man strdup*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strdup(char *src)
{
    char *str = malloc(sizeof(*src) * (ft_strlen((char *)src)) + 1);
    int i = 0;

    while(src[i] != '\0')
    {
        str[i] = src[i];
        i++;
    }
    
    ft_putstr(str);

}

int main(void)
{
    /*i mean it's just dumb but yeah, str there is *src, and strdup prints str, so, yeah...
    it duplicates...
    ffs...*/
    ft_strdup("hello is it me you're looking for");
    ft_putchar('\n');
    return (0);
}