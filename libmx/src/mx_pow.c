#include "libmx.h"
double mx_pow(double n, unsigned int pow)
{
    if(pow <= 0)
    {
        return 1;
    }
    else if(pow > 0)
    {
        double tmp = n;
        for(unsigned int i = 1; i < pow; i++)
        {
            n = n * tmp;
        }

    }
    return n;
}




