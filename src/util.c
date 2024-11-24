#include "util.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t *read_file(const char *path, size_t *len)
{
    FILE *fp = fopen(path, "rb");
    if (!fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t *buf = (uint8_t *)malloc(size);
    if (!buf) {
        fclose(fp);
        return NULL;
    }

    int n = 0;
    while (size > n) {
        int bytes_read = fread(buf + n, 1, READ_CHUNK, fp);
        if (bytes_read == 0)
            break;
        n += bytes_read;
    }

    fclose(fp);
    *len = size;
    return buf;
}