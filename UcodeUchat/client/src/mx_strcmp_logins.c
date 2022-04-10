#include "../inc/client.h"

int mx_strcmp_logins(const char *s1, const char s2[])
{
    for(; *s1; s1++, s2++)
	{
        if (*s1 != *s2)
		{
            break;
        }
    }
    return *s1 - *s2;
}

