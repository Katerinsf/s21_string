#include "s21_string.h"

// Appends the string pointed to, by src to the end of the string pointed to by dest
char *s21_strcat(char *dest, const char *src) {
    char *s = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++) != '\0') {
    }
    return s;
}
