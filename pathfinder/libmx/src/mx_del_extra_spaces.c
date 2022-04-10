#include "libmx.h"

char *mx_del_extra_spaces(const char *str) 
{
    char *buf = NULL;
    char *temp = NULL;
    int j = 0;

    if (!str) return NULL;
    
    buf = mx_strnew(mx_strlen(str));
    for(int i = 0; str[i]; i++) 
    {
        if (!(mx_isspace(str[i]))) 
        {
            buf[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) 
        {
            buf[j] = ' ';
            j++;
        }
        
    }
    temp = mx_strtrim(buf);
    mx_strdel(&buf);
    return temp;
}



