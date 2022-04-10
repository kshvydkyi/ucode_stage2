#include "header.h"

bool is_bl(int x, int *bl, int lines)
{
    for (int i = 0; i < lines; i++)
        if (bl[i] == x) return true;
    return false;
}
int create_route(char **Names, Path *path, int *len, int *weights, char *last, char **route, int *bl, int *blked, int *blAlways, int number_of_islands, int lines)
{
    int ves = -1, dlina = 0, last_weight = 0, steps = 1, lastbridge = -1, forward_bridge = -1, j = 0;
    char *ETOTName = last;
    route[0] = last;
    bool flag = true, out = true;
    while (j < number_of_islands + 1 && flag == true)
    {
        out = true;
        last_weight = get_weight(Names, weights, last, number_of_islands);
        for (int i = 0; i < lines - 1; i++)
        {
            if (is_bl(i, bl, (*blked)) == true) continue;
            else if (mx_strcmp(path[i].second_el, last) == 0)
            {
                ETOTName = path[i].first_el;
                ves = get_weight(Names, weights, path[i].first_el, number_of_islands);
                dlina = path[i].lenght_bridge;
            }
            else if (mx_strcmp(path[i].first_el, last) == 0)
            {
                ETOTName = path[i].second_el;
                ves = get_weight(Names, weights, path[i].second_el, number_of_islands);
                dlina = path[i].lenght_bridge;
            }
            else continue;
            if (last_weight < dlina) continue;
            else if (ves == 0)
            {
                bl[*blked] = i;
                (*blked)++;
                route[steps] = ETOTName;
                len[steps - 1] = dlina;
                steps++;
                forward_bridge = i;
                flag = false;
                out = false;
                break;
            }
            else if (last_weight - dlina == ves)
            {
                lastbridge = i;
                len[steps - 1] = dlina;
                last = ETOTName;
                route[steps] = last;
                steps++;
                out = false;
                break;
            }
        }
        if (out == true)
        {
            if (mx_strcmp(last, route[0]) == 0) return -1;
            else
            {
                j = 0;
                last = route[0];
                steps = 1;
                bl[*blked] = lastbridge;
                (*blked)++;
                if (mx_strcmp(path[lastbridge].first_el, route[0]) == 0 || mx_strcmp(path[lastbridge].second_el, route[0]) == 0)
                {
                    bl[*blAlways] = lastbridge;
                    (*blAlways)++;
                    *blked = *blAlways;
                }
            }
        }
        if (flag == false && (mx_strcmp(path[forward_bridge].first_el, route[0]) == 0 || mx_strcmp(path[forward_bridge].second_el, route[0])) == 0)
        {
            bl[*blAlways] = forward_bridge;
            (*blAlways)++;
            *blked = *blAlways;
        }
        j++;
    }
    route[steps] = NULL;
    return steps;
}






