#include "./s21_string.h"

// Breaks string str into a series of tokens separated by delim
char *s21_strtok(char *str, const char *delim) {
    static char * next;
    int k = 0;
    if (str) {
        next = str;
        while (*next && s21_strchr(delim, *next))
            *next++ = '\0';
    }
    if (!*next) {
        k = 1;
    } else {
        str = next;
        while (*next && !s21_strchr(delim, *next))
            ++next;
        while (*next && s21_strchr(delim, *next))
            *next++ = '\0';
    }
    return k ? s21_NULL : str;
}
