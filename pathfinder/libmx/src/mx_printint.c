#include "libmx.h"

void mx_printint(int n)
{
    if(n == 0)
    {
        mx_printchar('0');
    }
    if (n == -2147483648) 
    {
        write(1, "-21474", 6);
        write(1, "83648", 5);
        return;
    }
    if(n < 0)
    {
        mx_printchar('-');
        n *= -1;
    }

 
    int buf = n;
    int counter = 0;
    while(buf > 0)
    {
        buf /= 10;
        counter++;
    }
    char number[counter];
    for(int i = 0; i < counter; i++)
    {
        int j = n % 10;
        number[i] = j + 48;
        n /= 10;
    }
    for(int i = counter - 1; i >= 0; i--)
    {
        mx_printchar(number[i]);
    }
}



