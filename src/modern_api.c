#include "api_bridge_lab.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int modern_parse_year(const char *record, int *out_year) {
    if (record == NULL || out_year == NULL) {
        return -1;
    }

    const char *colon = strchr(record, ':');
    if (colon == NULL) {
        return -1;
    }

    const char *val = colon + 1;
    if (*val == '\0') {
        return -1;
    }

    char *endptr;
    errno = 0;
    long parsed = strtol(val, &endptr, 10);

    
    if (endptr == val) {
        return -1;
    }

    
    if (*endptr != '\0') {
        return -1;
    }

    
    if (errno == ERANGE || parsed < INT_MIN || parsed > INT_MAX) {
        return -1;
    }

    *out_year = (int)parsed;
    return 0;
}

int modern_make_slug(const char *name, char *out, size_t out_size) {
    if (name == NULL || out == NULL || out_size == 0) {
        return -1;
    }

    size_t i;
    for (i = 0; name[i] != '\0'; i++) {
        
        if (i + 1 >= out_size) {
            return -1;
        }

        if (name[i] == ' ') {
            out[i] = '_';
        } else {
            out[i] = (char)tolower((unsigned char)name[i]);
        }
    }

    out[i] = '\0';
    return 0;
}