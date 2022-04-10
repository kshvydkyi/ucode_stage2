#include "header.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    char *filename = argv[1];
    if(open(filename, 0) < 0) mx_printerr_mod("error: file ", filename," does not exist\n");
    int open_file = open(filename, 0);
    int file_size = 0;
    char c;
    while (read(open_file, &c, 1) > 0) file_size++;
    if (file_size == 0)
        mx_printerr_mod("error: file ", filename, " is empty\n");
    char *info = mx_file_to_str(filename);
    char **info_parsed = mx_strsplit(info, '\n');
    int lines = mx_count_words(info, '\n');
    int len_line1 = mx_strlen(info_parsed[0]);
    for(int i = 0; i < len_line1; i++)
    {
        if(!mx_isdigit(info_parsed[0][i]))
        {
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
        }
    }

    if(mx_atoi(info_parsed[0]) < 0 || mx_atoi(info_parsed[0]) > INT_MAX)
    {
        mx_printerr("error: line 1 is not valid\n");
        exit(-1);
    }
    int number_of_islands = mx_atoi(info_parsed[0]);
    
    for(int i = 1; i < lines; i++)
    {
        int bridge_counter = 0;
        int zapataya_counter = 0;
        for(int j = 0; j < mx_strlen(info_parsed[i]); j++)
        {
            if(info_parsed[i][j] == '-') bridge_counter++;
            if(info_parsed[i][j] == ',') zapataya_counter++;
            if(mx_isspace(info_parsed[i][j]))
                mx_printerr_mod("error: line ", mx_itoa(i + 1), " is not valid\n");
            if(info_parsed[i][j] == ',' && !mx_isdigit(info_parsed[i][j + 1]))
                mx_printerr_mod("error: line ", mx_itoa(i + 1), " is not valid\n");
        }
        if(bridge_counter != 1 || zapataya_counter != 1)
            mx_printerr_mod("error: line ", mx_itoa(i + 1), " is not valid\n");   
    }
    
    struct Path *path = malloc((lines - 1) * sizeof(Path));
    for(int i = 0; i < lines - 1; i++)
    {
        char **buf_info = mx_strsplit(info_parsed[i + 1], ',');
        char **buf_info1 = mx_strsplit(buf_info[0], '-');
        struct Path tmp = {buf_info1[0], buf_info1[1], mx_atoi(buf_info[1])};
        path[i] = tmp;
    }
    long long all_bridges_length = 0;
    for(int i = 0; i < lines - 1; i++)
    {
        for(int j = 0; j < mx_strlen(path[i].first_el); j++)
            if(!mx_isalpha(path[i].first_el[j]))
                mx_printerr_mod("error: line ", mx_itoa(i + 2),  " is not valid\n");
        for(int j = 0; j < mx_strlen(path[i].second_el); j++)
            if(!mx_isalpha(path[i].second_el[j]))
                mx_printerr_mod("error: line ", mx_itoa(i + 2),  " is not valid\n");
        if(!mx_strcmp(path[i].first_el, path[i].second_el))
            mx_printerr_mod("error: line ", mx_itoa(i + 2),  " is not valid\n");
        if(path[i].lenght_bridge <= 0)
            mx_printerr_mod("error: line ", mx_itoa(i + 2),  " is not valid\n");
        all_bridges_length += path[i].lenght_bridge;
        if(all_bridges_length > INT_MAX)
        {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(-1);
        }
    }
    int counter = 0;
    char **only_islands = (char**)malloc(number_of_islands);
    for(int i = 0; i < number_of_islands; i++) 
        only_islands[i] = (char*)malloc(512);
    for(int i = 0; i < lines - 1; i++)
    {
        int flag = 0;
        for (int j = i - 1; j > -1; j--)
        {
            if(mx_strcmp(path[i].first_el, path[j].first_el) == 0 || mx_strcmp(path[i].first_el, path[j].second_el) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            only_islands[counter] = path[i].first_el;
            counter++;
        }
    }
    for(int i = 0; i < lines - 1; i++)
    {
        int flag = 0;
        for (int j = i - 1; j > -1; j--)
        {
            if(mx_strcmp(path[i].second_el, path[j].second_el) == 0 || mx_strcmp(path[i].second_el, path[j].first_el) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            only_islands[counter] = path[i].second_el;
            counter++;
        }
    }
    if(counter != number_of_islands)
    {
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
    path = sort(path, only_islands, number_of_islands, lines);
    int *weights = malloc((number_of_islands + 1) * sizeof(int));
    for(int i = 0; i < number_of_islands - 1; i++)
    {
        for(int j = i + 1; j < number_of_islands; j++)
        {
            int blAlways = 0, count_i = 0, blocked = 0;
            int *len = (int *)malloc(number_of_islands);
            int *bl = (int *)malloc(lines - 1);
            char **route = malloc((number_of_islands + 1) * sizeof(*route));
            for(int k = 0; k < number_of_islands; k++) weights[k] = -1;
            for(int k = 0; k < number_of_islands; k++)
            {
                if(mx_strcmp(only_islands[k], only_islands[j]) == 0)
                {
                    weights[k] = 0;
                    break;
                }
            }
            set_weights(weights, only_islands, path, number_of_islands, lines);
            while(count_i != -1)
            {
                count_i = create_route(only_islands, path, len, weights, only_islands[i], route, bl, &blocked, &blAlways, number_of_islands, lines);
                if (count_i != -1) 
                {
                    struct Route routes = {route[0], route[count_i - 1], route, len, count_i};
                    print_path(routes);
                }
            }
        }
    }
}



