#include "s21_string.h"

// Searches for the first occurrence of the character c (an unsigned char)
// in the first n bytes of the string pointed to, by the argument str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *ptr = s21_NULL;
    unsigned char* temp = (unsigned char*) str;
    for (s21_size_t i = 0; i < n; i++) {
        if ((unsigned char) c == *(temp + i)) {
            ptr = temp + i;
            break;
        }
    }
    return ptr;
}
