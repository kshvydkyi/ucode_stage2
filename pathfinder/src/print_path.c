#include "header.h"

void print_path(Route route)
{
    mx_printstr("========================================\nPath: ");
    mx_printstr(route.first_el);
    mx_printstr(" -> ");
    mx_printstr(route.second_el);
    if(route.steps != 2)
    {
        int sum = route.Length[0];
        mx_printstr("\nRoute: ");
        mx_print_strarr(route.Pathes, " -> ");
        mx_printstr("Distance: ");
        mx_printint(route.Length[0]);
        for(int i = 1; i < route.steps - 1; i++)
        {
            mx_printstr(" + ");
            mx_printint(route.Length[i]);
            sum += route.Length[i]; 
        }
        mx_printstr(" = ");
        mx_printint(sum);
    }
    else
    {
        mx_printstr("\nRoute: ");
        mx_printstr(route.first_el);
        mx_printstr(" -> ");
        mx_printstr(route.second_el);
        mx_printstr("\nDistance: "); 
        mx_printint(route.Length[0]); 
    }
    mx_printstr("\n========================================\n");
}
