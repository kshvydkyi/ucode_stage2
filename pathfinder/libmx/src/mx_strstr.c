#include "libmx.h"
int mx_strncmp(const char *s1, const char *s2, int n)
{
    while (n--)
    {
        if (*s1 != *s2)
        {
            return *(const char*)s1 - *(const char*)s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
char *mx_strstr(const char *haystack, const char *needle)
{
    char *hay = (char *)haystack;
    char *nee = (char *)needle;
    if (!hay || !nee)
    {
        return NULL;
    }
    else if (!mx_strlen(nee))
    {
        return hay;
    }
    while (*hay) 
    {
        if (!mx_strncmp(hay, nee, mx_strlen(nee)))
        {
            return hay;
        }
        hay++;
    }
    return NULL;
}





