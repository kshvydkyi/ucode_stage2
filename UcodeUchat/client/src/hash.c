#include "../inc/client.h"

unsigned char *hash(unsigned char* Password)
{
    MD5_CTX hMD5;
    MD5_Init(&hMD5);
    Password = MD5(Password, mx_strlen((const char*)Password), (unsigned char*)&hMD5);
    return Password;
}

