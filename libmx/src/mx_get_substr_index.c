#include "libmx.h"
int mx_get_substr_index(const char *str, const char *sub)
{
    int count = mx_strlen(sub);
    if (sub != NULL && str != NULL)
    {
        for(int i = 0; *str ; i++)
        {
            if (mx_strncmp(str, sub, count))
            {
                return i;
            }
            str++;
        }
        return -1;
    }
    else
    {
        return -2;
    }
}







