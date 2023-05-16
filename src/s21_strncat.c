#include "s21_string.h"

// Appends the string pointed to, by src to the end
// of the string pointed to, by dest up to n characters long
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *s = dest;
    if (n) {
        while (*dest)
            dest++;
        while ((*dest++ = *src++) != '\0') {
            if (--n == 0) {
                *dest = '\0';
                break;
            }
        }
    }
    return s;
}
