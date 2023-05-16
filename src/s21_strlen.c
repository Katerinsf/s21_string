#include "s21_string.h"

// Computes the length of the string str up to
// but not including the terminating null character
s21_size_t s21_strlen(const char *str) {
    s21_size_t i;
    for (i = 0; str[i] != '\0'; i++) {}
    return i;
}
