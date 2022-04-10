#include "../inc/client.h"

int message_sizeH(char *message)
{     
    int height = 10;  
    int len = strlen(message);
    int aboba = len / 50;
   
    for (int i = 0; i < aboba; i++)
    {
        height += 10;
    }
    return height; 
}

int message_sizeW(char *message)
{  
    int len = strlen(message);
    int width = 0; 
    if (len <= 0)
    {
        width = 0;
    }
    if(len <= 50)
    {
        width = len * 2;
    }
    else if(len >= 50)
    {
        width = 100;
    }
    return width;
}

int search_person_sizeW(const char *name)
{  
    int len = strlen(name);
    int width = 0;
    if (len <= 0)
    {
        width = 0;
    }
    if(len <= 50)
    {
        width = len * 2;
    }
    else if(len >= 50)
    {
        width = 100;
    }
    return width;
}

