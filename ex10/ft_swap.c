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
    else if (n >= 0 && n < 10)
    {
        /*ascii 0 = 48*/
        ft_putchar(n + 48);
    }
    else
    {
        /*e.g. if n = 1337:
        ft_putchar n/10:
        extracts all values divisible by 10 from input value.
        1337 becomes 133, 7 ignored.
        /*ft_putchar n%10: 
        extracts last value of input.
        1337 % 10 --> prints 7.
        logic:
        1000 & 10 --> 100, none over.
        300 % 10 --> 30, none over.
        either:
        37 % 10 --> 3, 7 over --> result = 7.
        or:
        30 % 10 --> 3, none over.
        7 % 10 --> 0, 7 over. */
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

void ft_swap(int *a, int *b)
{
    int t;

    /*first store the value of a-pointer into placeholder t.*/
    t = *a;
    /*then set a-pointer to value of b-pointer.*/
    *a = *b;
    /*assing a-pointer's original value to b-pointer*/
    *b = t;

}

int main(void)
{
    /*things for pointers to point to*/
    int a = 42;
    int b = 24;

    /*pointers for ft_swap that point to things*/
    int *c = &a;
    int *d = &b;

    /*display original values*/
    ft_putnbr(a);
    ft_putnbr(b);
    ft_putchar('\n');
    /*use pointers to swap values*/
    ft_swap(c, d);
    /*TA-DA OMG THEY'RE CHANGED WTF WHOA*/
    ft_putnbr(a);
    ft_putnbr(b);
    ft_putchar('\n');

}