#include "s21_string.h"

// Copies the string pointed to, by src to dest
char* s21_strcpy(char* dest, const char* src) {
    char* tmp = dest;
    while ((* dest++ = * src++) != '\0') {
    }
    return tmp;
}
