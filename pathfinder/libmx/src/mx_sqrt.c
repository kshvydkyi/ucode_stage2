#include "libmx.h"
int mx_sqrt(int x)
{
    if (x <= 0)
    {
        return 0;
    }
    if(x == 1)
    {
        return 1;
    }
    for(int i = 1; x > i * i && i * i > 0;)
    {
        i++;
        if (i * i == x)
        {
            return i;
        }
    }
    return 0;
}






