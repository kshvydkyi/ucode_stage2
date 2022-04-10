#include "header.h"

int get_weight(char **only_islands, int *weights, char *Name, int number_of_islands)
{
    for (int i = 0; i < number_of_islands; i++)
        if (mx_strcmp(only_islands[i], Name) == 0) return weights[i];
    return 0;
}




