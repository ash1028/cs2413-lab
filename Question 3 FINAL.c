#include "Student.h"
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int i;
    int* out = (int*)malloc((size_t)(digitsSize + 1) * sizeof(int));
    if (!out) {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i < digitsSize; i++) {
        out[i + 1] = digits[i];
    }

    i = digitsSize;
    out[i] = out[i] + 1;

    while (i > 0 && out[i] == 10) {
        out[i] = 0;
        out[i - 1] = out[i - 1] + 1;
        i--;
    }

    if (out[0] == 10) {
        out[0] = 1;
        *returnSize = digitsSize + 1;
        return out;
    } else {
        int* ans = (int*)malloc((size_t)digitsSize * sizeof(int));
        if (!ans) {
            free(out);
            *returnSize = 0;
            return NULL;
        }

        for (i = 0; i < digitsSize; i++) {
            ans[i] = out[i + 1];
        }

        free(out);
        *returnSize = digitsSize;
        return ans;
    }
}
