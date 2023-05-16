#include "s21_string.h"

// Copies the character c (an unsigned char) to the first n characters
// of the string pointed to, by the argument str
void *s21_memset(void *str, int c, s21_size_t n) {
    char *s = (char*) str;
    while (n--) {
        *s = c;
        s = s + 1;
    }
    return str;
}
