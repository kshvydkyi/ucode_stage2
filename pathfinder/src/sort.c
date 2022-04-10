#include "header.h"

int get_id(char **Names, char *Name, int number_of_islands)
{
    for (int i = 0; i < number_of_islands; i++)
    {
        if (mx_strcmp(Names[i], Name) == 0) return i;
    }
    return -1;
}

Path * sort(Path *path, char** only_islands, int number_of_islands, int lines)
{
    for (int i = 0; i < lines - 1; i++)
    {
        for (int j = i + 1; j < lines - 1; j++)
        {
            if (get_id(only_islands, path[i].first_el, number_of_islands) + get_id(only_islands, path[i].second_el, number_of_islands) > get_id(only_islands, path[j].first_el, number_of_islands) + get_id(only_islands, path[j].second_el, number_of_islands))
            {
                struct Path tmp = {path[i].first_el, path[i].second_el,  path[i].lenght_bridge};
                path[i] = path[j];
                path[j] = tmp;
            }
        }
    }
    return path;
}




