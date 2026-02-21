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
From: Thompson, Ashton <ashtotho@ttu.edu>
Sent: Friday, February 20, 2026 7:51 PM
To: Thompson, Ashton <ashtotho@ttu.edu>
Subject: Re: Re:
 
#include "Student.h"

int majorityElement(int* nums, int numsSize) {

    int candidate = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {

        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}