#include "libmx.h"

int mx_count_words(const char *str, char c) 
{
    bool flag = true;
    unsigned countwords = 0;
    
    if (str == NULL)
        return -1;
    else 
    {
        for(int i = 0; str[i] ; ++i) 
        {
            if (str[i] == c)
            {
                flag = true;
            }
            else if (flag == true) 
            {
                flag = false;
                ++countwords;
            }
        }
        return countwords;
    }
}






