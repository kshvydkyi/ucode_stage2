#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) 
{
    int iterations = 0;
    int first = left;
    int last = right;
    if(arr == NULL)
    {
        return -1;
    }
    else if (left < right) 
    {
        int middle = (first + last) / 2;
        for(;first <= last;) 
        {
            for(;mx_strlen(arr[first]) < mx_strlen(arr[middle]);) 
            {
                first++;
            }
            for(;mx_strlen(arr[last]) > mx_strlen(arr[middle]);) 
            {
                last--;
            }
            char *tmp;
            tmp = arr[first];
            arr[first] = arr[last];
            arr[last] = tmp;
            first++;
            last--;
            iterations++;
        }
        mx_quicksort(arr, left, last);
        mx_quicksort(arr, first, right);
    }
    return iterations;
}



