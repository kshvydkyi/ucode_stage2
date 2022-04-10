#include "ush.h"

void mx_unset(Rasparshennaya_khuynya *unset_p)
{
    if(!unset_p->params)
    {
        mx_printerr("unset: not enough arguments\n");
    }
    else
    {
        char **params = mx_strsplit(unset_p->params, '\1');
        while(*params)
        {
            unsetenv(*params++);
        }
    }
}

