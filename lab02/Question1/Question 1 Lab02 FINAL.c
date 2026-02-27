#include "Student.h"
#include <stdbool.h>
#include <string.h>

bool isValid(const char *s) {
    if (s == NULL) {
        return false;
    }

    int len = strlen(s);

    if (len % 2 != 0) {
        return false;
    }

    char stack[len];
    int top = 0;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[top] = c;
            top++;
        } else {
            if (top == 0) {
                return false;
            }

            top--;
            char open = stack[top];

            if (c == ')' && open != '(') return false;
            if (c == ']' && open != '[') return false;
            if (c == '}' && open != '{') return false;
        }
    }

    return top == 0;
}