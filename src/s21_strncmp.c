#include "s21_string.h"

// Compares at most the first n bytes of str1 and str2
int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
    unsigned char c1, c2;
    int k = 0;
    while (n) {
        c1 = * str1++;
        c2 = * str2++;
        if (c1 != c2) {
            k = c1 - c2;
            break;
        }
        n--;
    }
    return k;
}
