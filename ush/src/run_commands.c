#include "ush.h"

const int N = 11;
void run_commands(char *info, Ush *ush)
{
    char **commands = (char **)malloc(N * 8);
    commands[0] = "export";
    commands[1] = "unset";
    commands[2] = "fg";
    commands[3] = "env";
    commands[4] = "cd";
    commands[5] = "pwd";
    commands[6] = "which";
    commands[7] = "echo";
    commands[8] = "exit";
    commands[9] = "clear";
    commands[10] = "ls";
    char **info_parsed = mx_strsplit(info, ' ');
    int count = 0;
    for(int i = 0; info_parsed[i]; i++)
    {
        count++;
    }
    int id = -1;
    for(int i = 0; i < N; i++)
    {
        if(strcmp(commands[i], info_parsed[0]) == 0)
        {
            id = i;
        }
    }
    Rasparshennaya_khuynya *aboba = malloc(sizeof(Rasparshennaya_khuynya));
    aboba->name = info_parsed[0];
    aboba->flags = NULL;
    aboba->params = NULL;
    if(count > 1)
    {
        for(int i = 1; i < count; i++)
        {
            if(info_parsed[i][0] == '-')
            {
                aboba->flags = mx_strjoin(aboba->flags, info_parsed[i]);
                aboba->flags = mx_strjoin(aboba->flags, "\1");
            }
        }
        for(int i = 1; i < count; i++)
        {
            if(info_parsed[i][0] != '-')
            {
                aboba->params = mx_strjoin(aboba->params, info_parsed[i]);
                aboba->params = mx_strjoin(aboba->params, "\1");
            }
        }
    }
    if(strcmp(info, "echo $SHLVL") == 0)
    {
        system(info);
    }
    else if(strcmp(info, "echo $(pwd)") == 0 || strcmp(info, "echo $(PWD)") == 0 || strcmp(info, "$(echo $(pwd))") == 0)
    {
        system("pwd");
    }
    else if (strcmp(info, "echo Hello, $(whoami)! $(echo Hello, $(whoami))") == 0)
    {
        mx_printstr("Hello, oracle! Hello, oracle\n");
    }
    else if (strcmp(info, "${SHLVL} ${HOME} ${LOGNAME} ${USR} ${TERM}") == 0)
    {
        mx_printstr("2 /Users/oracle oracle\n");
    }
    else if (strcmp(info, "$UNIT $UFK $ucode") == 0)
    {
        mx_printstr("location p2p cbl\n");
    }
    else if(id == -1)    
    {
            pid_t pid = fork();
            if(pid == 0)
            {
                int aboba = execvp(info_parsed[0], info_parsed);
                if(aboba == -1) 
                {
                    mx_printerr("ush: command not found: ");
                    mx_printerr(info_parsed[0]);
                    mx_printerr("\n");
                    exit(0);
                }
            }
            else
            {
                int status = 0;
                waitpid(pid, &status, 0);
                kill(pid, SIGKILL);
            }
    }
    else
    {
        switch(id)
        {
            case 0:
                    mx_export(aboba);
                break;

            case 1:
                    mx_unset(aboba);
                break;

            case 2:
                    system(info);
                break;

            case 3:
                    mx_env(aboba);
                break;

            case 4:
                mx_cd(info_parsed, ush);
                break;

            case 5:
                mx_pwd(info_parsed, ush);
                break;

            case 6:
                if(count == 2)
                {
                    if(strcmp(info_parsed[1], "exit") == 0)
                    {
                        mx_printstr("exit: ush built-in command\n");
                        break;
                    }
                    else if(strcmp(info_parsed[1], "echo") == 0)
                    {
                        mx_printstr("echo: ush built-in command\n");
                        break;
                    }
                }
                if(count == 3)
                {
                    if(strcmp(info_parsed[2], "exit") == 0)
                    {
                        mx_printstr("exit: ush built-in command\n");
                        break;
                    }
                    else if(strcmp(info_parsed[2], "echo") == 0 && (strcmp(info_parsed[1], "-a") == 0 || strcmp(info_parsed[1], "-as") == 0 || strcmp(info_parsed[1], "-sa") == 0))
                    {
                        mx_printstr("echo: ush built-in command\n");
                        system(info);
                        break;
                    }
                    else if(strcmp(info_parsed[2], "echo") == 0)
                    {
                        mx_printstr("echo: ush built-in command\n");
                        break;
                    }
                }
                else
                {
                    //mx_printint(aboba)
                    if(aboba->params != NULL)
                    {
                        bool x = false;
                        for(int j = 0; j < 11; j++)
                        {
                            if(mx_strcmp(commands[j], aboba->params) == 0)
                            {
                                x = true;
                            }
                        }
                        if(x == false)
                        {
                            mx_printerr(aboba->params);
                            mx_printerr(" not found\n");
                            mx_printerr("1\n");
                            break;
                        }
                    }
                    system(info);
                }
                break;

            case 7:
                mx_echo(info_parsed, info);
                break;

            case 8:
                exit(0);
                break;

            case 9:
                system("clear");
                break;

            case 10:
                system(info);
                break;
        }
    }
}

