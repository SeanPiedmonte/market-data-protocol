#ifndef READER_H
#define READER_H
#define CACHE_SIZE 192 * 1024
#endif

#include "stdlib.h"
#include "stdio.h"

void ReadToMemoryFile(char *source, unsigned char *buffer, int pos, int size);
