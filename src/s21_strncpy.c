#include "s21_string.h"

// Copies up to n characters from the string pointed to, by src to dest
char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
    char* tmp = dest;
    while (n) {
        if ((* tmp = * src) != 0) {
            src++;
        }
        tmp++;
        n--;
    }
    return dest;
}
