#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) 
{
    int counter = 0;
    const char *temp_str = str;

    for(;mx_strstr(temp_str,sub);) 
    {
        temp_str = mx_strstr(temp_str, sub);
        for (int i = 0; i < mx_strlen(sub); i++) 
        {
            temp_str++;
        }
            counter++;
    }
    return counter;
}





