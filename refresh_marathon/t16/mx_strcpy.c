char *mx_strcpy(char *dst, const char *src)
{
    int counter = 0;
    char endchar = '\0';
    for(int i = 0; src[i] != endchar; i++)
    {
        dst[i] = src[i];
        counter++;
    }
    dst[counter] = '\0';
    return dst;
}







