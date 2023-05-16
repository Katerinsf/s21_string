#include "s21_string.h"

// Compares the string pointed to, by str1 to the string pointed to by str2
int s21_strcmp(const char* str1, const char* str2) {
    unsigned char c1, c2;
    int n = 0;
    while (1) {
        c1 = * str1++;
        c2 = * str2++;
        if (c1 != c2) {
            n = c1 - c2;
            break;
        }
        if (!c1) {
            break;
        }
    }
    return n;
}
