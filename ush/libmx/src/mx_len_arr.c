#include "libmx.h"

int mx_len_arr(char **arr) 
{
    if (arr == NULL) 
    {
        return 0;
    }
    int len = 0;
    for (; arr[len]; len++) ;
    return len;
}

