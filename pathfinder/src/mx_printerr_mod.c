#include "header.h"

void mx_printerr_mod(char *first_str, char *cause_of_err, char *second_str)
{
    mx_printerr(first_str);
    mx_printerr(cause_of_err);
    mx_printerr(second_str);
    exit(-1);
}



