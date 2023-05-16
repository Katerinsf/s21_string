#include "s21_string.h"

// Another function to copy n characters from src to dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *temp1;
    char *temp2;
    int shift = 0;
    if (dest < src) {
        temp1 = (char*)dest;
        temp2 = (char*)src;
        shift = 1;
    } else {
        temp1 = (char*)dest + n - 1;
        temp2 = (char*)src + n - 1;
        shift = -1;
    }
    for (s21_size_t i = 0; i < n; i++) {
        *temp1 = *temp2;
        temp1+=shift;
        temp2+=shift;
    }
    return dest;
}
