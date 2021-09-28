#include "hamming.h"

#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (strlen(lhs) != strlen(rhs)) {
        return -1;
    }

    int diffCount = 0;

    for (size_t index = 0; index < strlen(lhs); index++) {
        if (lhs[index] != rhs[index]) {
            diffCount++;
        }
    }

    return diffCount;
}
