#include "ush.h"

void mx_export(Rasparshennaya_khuynya* export_p)
{
    if (!export_p->params)
    {
        char **str_array = (char **)malloc(sizeof(char *) * (mx_len_arr(env) + 1));
        for (int i = 0; env[i]; i++)
        {
            str_array[i] = mx_strdup(env[i]);
        }
        str_array[mx_len_arr(env)] = NULL;
        mx_bubble_sort(str_array, mx_len_arr(str_array));
        mx_print_env(str_array);
    }
    else
    {
        char **str_array = mx_strsplit(export_p->params, '\1');
        for (int i = 0; str_array[i]; i++)
        {
            char *name = NULL;
            char *value = NULL;
            for (int j = 0; str_array[i][j] != '\0'; j++)
            {
                if (str_array[i][j] == '=')
                {
                    name = mx_strndup(str_array[i], j);
                    value = mx_strdup(&str_array[i][j + 1]);
                }
            }
            bool s = true;
            if (name == NULL)
            {
                name = mx_strdup(str_array[i]);
            }
            if (value == NULL)
            {
                value = "";
                s = false;
            }
            if (name)
            {
                setenv(name, value, s);
            }
        }
    }
}
