#pragma once

#define BUFFER_LEN 2048
#define BACKLOG 10
char* port;

#include <../../libraries/openssl/include/openssl/bio.h>
#include <../../libraries/openssl/include/openssl/buffer.h>
#include <../../libraries/openssl/include/openssl/des.h>
#include <../../libraries/openssl/include/openssl/evp.h>
#include <../../libraries/openssl/include/openssl/pem.h>
#include <../../libraries/openssl/include/openssl/rsa.h>
#include <../../libraries/openssl/include/openssl/ssl.h>
#include <../../libraries/openssl/include/openssl/err.h>
// #include <../../libraries/openssl/include/openssl/applink.h>

#include "../../libraries/libs/include/sqlite3.h"
#include "../../libraries/libs/include/cJSON.h"
//Includes
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <../libmx/inc/libmx.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>





