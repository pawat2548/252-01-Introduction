#include "api_bridge_lab.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int legacy_parse_year(const char *record) {
    const char *colon;

    colon = strchr(record, ':');
    if (colon == NULL) {
        return 0;
    }

    return atoi(colon + 1);
}

void legacy_make_slug(const char *name, char *out) {
    size_t i;

    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            out[i] = '_';
        } else {
            out[i] = (char)tolower((unsigned char)name[i]);
        }
    }
    out[i] = '\0';
}