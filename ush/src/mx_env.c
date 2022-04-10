#include "ush.h"

void mx_print_env(char **str)
{
    if (str)
    {
        for (int i = 0; str[i]; i++)
        {
            mx_printstr(str[i]);
            if (str[i][mx_strlen(str[i]) - 1] == '=')
            {
                mx_printstr("''");
            }
            mx_printchar('\n');
        }
    }
    else
    {
        for (int i = 0; env[i]; i++)
        {
            mx_printstr(env[i]);
            mx_printchar('\n');
        }
    }
}

void print_env_error(char str)
{
    mx_printerr("env: illegal option -- ");
    mx_print_char_err(str);
    mx_printerr("\n");
    mx_printerr("usage: env [-i] [-P utilpath] [-u name]\n");
    mx_printerr("           [name=value ...] [utility [argument ...]]\n");
}

void mx_add_to_arr(char ***arr, char *item)
{
    int len = 0;
    if (arr == NULL)
    {
        *arr = malloc(sizeof(char *) * 2);
        *arr[0] = item;
        *arr[1] = NULL;
    }
    else
    {
        len = mx_len_arr(*arr);
        *arr[len] = item;
        *arr = mx_realloc(*arr, sizeof(char *) * ++len);
        *arr[len] = NULL;
    }
}

void mx_env(Rasparshennaya_khuynya *env_p)
{
    int cmd_start = 0;
    char **saved_env = environ;
    char **custom_env = NULL;
    char **path = NULL;
    bool flag_u = false;
    bool flag_P = false;
    bool flag_i = false;
    if (!env_p->params && !env_p->flags)
    {
        mx_print_env(environ);
        return;
    }
    char **flags = env_p->flags ? mx_strsplit(env_p->flags, '\1') : NULL;
    char **params = env_p->params ? mx_strsplit(env_p->params, '\1') : NULL;
    for (int i = 0; flags && flags[i]; i++)
    {
        for (int j = 1; flags[i][j]; j++)
        {
            if (flags[i][j] == 'u')
            {
                flag_u = true;
            }
            else if (flags[i][j] == 'P')
            {
                flag_P = true;
                mx_add_to_arr(&path, params[0]);
            }
            else if (flags[i][j] == 'i')
            {
                flag_i = true;
            }
            else
            {
                print_env_error(flags[i][j]);
                return;
            }
        }
        for (int i = flag_P ? 1 : 0; params && params[0]; i++)
        {
            if (params[i][0] != '-')
            {
                break;
            }
            for (int j = 0; params[i][j]; j++)
            {
                if (params[i][j] == 'u')
                {
                    flag_u = true;
                }
                else if (params[i][j] == 'P')
                {
                    flag_P = true;
                    if (!params[i + 1])
                    {
                        print_env_error('P');
                    }
                    mx_add_to_arr(&path, mx_strdup(params[i + 1]));
                }
                else if (params[i][j] == 'i')
                {
                    flag_i = true;
                }
                else
                {
                    print_env_error(params[i][j]);
                    return;
                }
            }
        }
    }

    for (; params && params[cmd_start]; cmd_start++)
    {
        if (mx_strchr(params[cmd_start], '='))
        {
            mx_add_to_arr(&custom_env, mx_strdup(params[cmd_start]));
        }
        break;
    }

    if (flag_i == false)
    {
        int count = mx_len_arr(custom_env);
        char ***splited_vars = malloc(sizeof(char **) * count);
        for (int i = 0; custom_env[i]; i++)
        {
            splited_vars[i] = mx_strsplit(custom_env[i], '=');
            setenv(splited_vars[i][0], splited_vars[i][1], true);
        }
        if (params && params[cmd_start])
        {
            int pid = fork();
            if (pid == 0)
            {
                if (execvp(params[cmd_start], &params[cmd_start]))
                {
                    perror(params[cmd_start]);
                }
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            mx_print_env(environ);
        }
        for (int i = 0; custom_env[i]; i++)
        {
            unsetenv(splited_vars[i][0]);
            mx_del_strarr(&splited_vars[i]);
        }
    }
    else
    {
        if (!params || !params[cmd_start])
        {
            mx_print_env(custom_env);
        }
        else
        {
            errno = 0;
            int pid = fork();
            if (pid == 0)
            {
                environ = custom_env;
                if (execvp(params[cmd_start], &params[cmd_start]))
                {
                    perror(params[cmd_start]);
                }
                environ = saved_env;
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }
    }
}

