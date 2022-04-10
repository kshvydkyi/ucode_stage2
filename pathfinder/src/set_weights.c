#include "header.h"

void make_weight(int **weights, char **only_islands, char *str, int weight, int number_of_islands)
{
    for (int i = 0; i < number_of_islands; i++)
    {
        if (mx_strcmp(only_islands[i], str) == 0)
        {
            if ((*weights)[i] < weight && (*weights)[i] > 0) return;
            (*weights)[i] = weight;
            return;
        }
    }
}
bool if_vizited(char **visited, char *visit, int visits)
{
    for (int i = 0; i < visits; i++)
        if (mx_strcmp(visited[i], visit) == 0) return true;
    return false;
}

void set_weights(int *weights, char **Names, Path *bridges, int number_of_islands, int lines)
{
    char **visited = malloc(number_of_islands * sizeof(*visited));
    char *current;
    int visits = 0, min_id = 0, weight = 0;
    for (int i = 0; i < number_of_islands; i++)
    {
        min_id = 0;
        while(if_vizited(visited, Names[min_id], visits)) min_id++;
        if (visits == number_of_islands) break;
        for (int j = 0; j < number_of_islands; j++)
        {
            if (if_vizited(visited, Names[j], visits)) continue;
            if (weights[j] > -1 && (weights[min_id] < 0 || weights[min_id] > weights[j])) min_id = j;
        }
        current = Names[min_id];
        for (int j = 0; j < lines - 1; j++)
        {
            if (mx_strcmp(bridges[j].first_el, current) == 0)
            {
                if (if_vizited(visited, bridges[j].second_el, visits)) continue;
                weight = get_weight(Names, weights, current, number_of_islands);
                make_weight(&weights, Names, bridges[j].second_el, weight + bridges[j].lenght_bridge, number_of_islands);
            }
            else if (mx_strcmp(bridges[j].second_el, current) == 0)
            {
                if (if_vizited(visited, bridges[j].first_el, visits)) continue;
                weight = get_weight(Names, weights, current, number_of_islands);
                make_weight(&weights, Names, bridges[j].first_el, weight + bridges[j].lenght_bridge, number_of_islands);
            }
        }
        visited[visits] = current;
        visits++;
    }
    free(visited);
}





