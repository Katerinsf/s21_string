#include "s21_string.h"

// Compares the first n bytes of str1 and str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int res = 0;
    unsigned char* temp1 = (unsigned char*) str1;
    unsigned char* temp2 = (unsigned char*) str2;

    while (--n && *temp1 == *temp2) {
        temp1++;
        temp2++;
    }
    res = *temp1 - *temp2;
    return res;
}
