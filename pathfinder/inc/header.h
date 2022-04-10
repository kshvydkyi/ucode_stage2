#pragma once

#include "libmx.h"

typedef struct Path
{
    char *first_el;
    char *second_el;
    int lenght_bridge;
}
Path;

typedef struct Route
{
    char *first_el;
    char *second_el;
    char **Pathes;
    int *Length;
    int steps;
}
Route;

Path * sort(Path *path, char** only_islands, int number_of_islands, int lines);

void set_weights(int *weights, char **only_islands, Path *path, int number_of_islands, int lines);
void make_weight(int **weights, char **only_islands, char *str, int weight, int number_of_islands);
bool if_vizited(char **visited, char *visit, int visits);
void mx_printerr_mod(char *first_str, char *filename, char *second_str);
int get_weight(char **only_islands, int *weights, char *Name, int number_of_islands);
int create_route(char **Names, Path *path, int *len, int *weights, char *last, char **route, int *bl, int *blked, int *blAlways, int number_of_islands, int lines);

void print_path(Route route);


